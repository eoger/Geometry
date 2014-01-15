#include "LoadCommand.h"
#include <fstream>
#include <boost/regex.hpp>

#include "../Geometry.h"
#include "../Model.h"

LoadCommand::LoadCommand ( Geometry * geometry , std::string filename ) :
	Command ( geometry ), m_filename ( filename )
{
}

LoadCommand::~LoadCommand ( )
{
}

bool LoadCommand::Execute ( Model * model )
{
	std::ifstream file ( m_filename.c_str ( ) );
	if ( !file )
	{
		return false;
	}
	
	boost::regex regex ( "^(?:C|R|L|PL|OA) ([A-Za-z0-9]+)" );
	
	while ( !file.eof ( ) )
	{
		boost::smatch matches;
		std::string cmd;
		
		getline ( file , cmd );
		
		if ( !boost::regex_search ( cmd , matches , regex ) )
		{
			return false;
		}
		
		if ( CMD_OK == m_geometry->Parse ( cmd , false ) )
		{
			m_objs.push_back ( matches [ 1 ] );
		}
		else
		{
			Undo ( model );
			return false;
		}
	}
	
	return true;
}

void LoadCommand::Undo ( Model * model )
{
	for ( std::vector < std::string >::iterator it = m_objs.begin ( ) ;
		it != m_objs.end ( ) ; it++ )
	{
		model->DeleteElement ( *it );
	}
	m_objs.clear ( );
}
