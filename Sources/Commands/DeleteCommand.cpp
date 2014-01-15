#include "DeleteCommand.h"
#include <fstream>
#include <boost/regex.hpp>

#include "../Geometry.h"
#include "../Model.h"


DeleteCommand::DeleteCommand ( Geometry * geometry ,
	std::set < std::string > & elements ) :
	Command ( geometry ), m_elements ( elements )
{
}

DeleteCommand::~DeleteCommand ( )
{
}

bool DeleteCommand::Execute ( Model * model )
{
	for ( std::set < std::string >::iterator it = m_elements.begin ( ) ;
		it != m_elements.end ( ) ; it++ )
	{
		std::vector < std::string > incls = model->GetInclusions ( *it );
		std::string description;
		description = model->Description ( *it );
		
		if ( model->DeleteElement ( *it ) )
		{
			m_deletedObjs [ description ] = incls;
		}
		else
		{
			Undo ( model );
			return false;
		}
	}
	return true;
}

void DeleteCommand::Undo ( Model * model )
{
	boost::regex regex ( "^(?:C|R|L|PL|OA) ([A-Za-z0-9]+)" );
	
	for ( std::map < std::string , std::vector < std::string > >::iterator it =
		m_deletedObjs.begin ( ) ; it != m_deletedObjs.end ( ) ; it++ )
	{
		std::string cmd = it->first;
		m_geometry->Parse ( cmd , false );
		
		boost::smatch matches;
		boost::regex_search ( cmd , matches , regex );
		
		std::string name = matches [ 1 ];
		std::vector < std::string > aggregates = it->second;
		
		for ( std::vector < std::string >::iterator it2 = aggregates.begin ( ) ;
			it2 != aggregates.end ( ) ; it2++ )
		{
			model->AddToAggregate ( name , *it2 );
		}
	}
}
