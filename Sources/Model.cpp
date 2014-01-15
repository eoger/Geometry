#include "Model.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <utility>

#include "GeoElements/Aggregate.h"
#include "GeoElements/Circle.h"
#include "GeoElements/Polyline.h"
#include "GeoElements/Rectangle.h"

Model::Model ( )
{
}

Model::~Model ( )
{
	Clear ( );
}

bool Model::CreateAggregate ( std::string element , std::set < std::string > & elements )
{
	if ( m_elements.find ( element ) != m_elements.end ( ) )
	{
		return false;
	}
	else
	{
		std::map < std::string , GeoElement * > elts = getElements ( elements );
		if ( elements.size ( ) != elts.size ( ) )
		{
			return false;
		}
		m_elements [ element ] = new Aggregate ( element , elts );
		return true;
	}
}

bool Model::CreateCircle ( std::string element , long x1 , long y1 ,
	unsigned long radius )
{
	if ( m_elements.find ( element ) != m_elements.end ( ) )
	{
		return false;
	}
	else
	{
		m_elements [ element ] = new Circle ( element , x1 , y1 , radius );
		return true;
	}
}

bool Model::CreateLine ( std::string element , long x1 , long y1 , long x2 , long y2 )
{
	if ( m_elements.find ( element ) != m_elements.end ( ) )
	{
		return false;
	}
	else
	{
		m_elements [ element ] = new Line ( element , x1 , y1 , x2 , y2 );
		return true;
	}
}

bool Model::CreatePolyline ( std::string element , std::vector < Line > lines )
{
	if ( m_elements.find ( element ) != m_elements.end ( ) )
	{
		return false;
	}
	else
	{
		m_elements [ element ] = new Polyline ( element , lines );
		return true;
	}
}

bool Model::CreateRectangle ( std::string element , long x1 , long y1 , long x2 ,
	long y2 )
{
	if ( m_elements.find ( element ) != m_elements.end ( ) )
	{
		return false;
	}
	else
	{
		m_elements [ element ] = new Rectangle ( element , x1 , y1 , x2 , y2 );
		return true;
	}
}

bool Model::Move ( std::string element , long x , long y )
{
	if ( m_elements.find ( element ) == m_elements.end ( ) )
	{
		return false;
	}
	else
	{
		m_elements [ element ]->Move ( x , y );
		return true;
	}
}

bool Model::AddToAggregate ( std::string nameObj , std::string nameAggregate )
{
	GeoElement * elt;
	std::map < std::string , GeoElement * >::iterator it = m_elements.find ( nameObj );
	if ( it == m_elements.end ( ) )
	{
		return false;
	}
	
	elt = it->second;
	
	it = m_elements.find ( nameAggregate );
	if ( it == m_elements.end ( ) )
	{
		return false;
	}
	
	if ( Aggregate *pAggregate = dynamic_cast < Aggregate* > ( it->second ) )
	{
		return pAggregate->AddElement ( elt );
	}
	else
	{
		return false;
	}
	
}

bool Model::DeleteElement ( std::string element )
{
	std::map < std::string , GeoElement * >::iterator it = m_elements.find ( element );
	if ( it == m_elements.end ( ) )
	{
		return false;
	}
	delete it->second;
	m_elements.erase ( it );
	return true;
}

std::string Model::Description ( )
{
	std::stringstream description;
	for ( std::map < std::string , GeoElement * >::iterator it = m_elements.begin ( ) ;
		it != m_elements.end ( ) ; it++ )
	{
		description << it->second->Description ( ) << std::endl;
	}
	return description.str ( );
}

std::string Model::Description ( std::string obj )
{
	std::map < std::string , GeoElement * >::iterator it = m_elements.find ( obj );
	if ( it == m_elements.end ( ) )
	{
		return "";
	}
	else
	{
		return it->second->Description ( );
	}
}

std::string Model::DescriptionSerialized ( )
{
	std::vector < std::string > visited;
	std::stringstream description;
	
	description << descriptionSerialized ( m_elements , visited );
	
	return description.str ( );
	
}

template < typename T >
std::string Model::descriptionSerialized ( std::map < std::string , GeoElement * , T > elements ,
	std::vector < std::string > & visited )
{
	std::stringstream description;
	
	for ( std::map < std::string , GeoElement * >::iterator it = elements.begin ( ) ;
		it != elements.end ( ) ; it++ )
	{
		
		if ( std::find ( visited.begin ( ) , visited.end ( ) , it->first )
			!= visited.end ( ) )
		{
			continue;
		}
		
		if ( Aggregate *pAggregate = dynamic_cast < Aggregate* > ( it->second ) )
		{
			description
				<< descriptionSerialized ( pAggregate->GetElements ( ) , visited );
		}
		
		description << it->second->Description ( ) << std::endl;
		visited.push_back ( it->first );
	}
	return description.str ( );
}

void Model::Clear ( )
{
	for ( std::map < std::string , GeoElement * >::iterator it = m_elements.begin ( ) ;
		it != m_elements.end ( ) ; it++ )
	{
		delete m_elements [ it->first ];
	}
	m_elements.clear ( );
}

std::vector < std::string > Model::GetInclusions ( std::string element )
{
	std::vector < std::string > incl;
	std::map < std::string , GeoElement * >::iterator it = m_elements.find ( element );
	if ( it != m_elements.end ( ) )
	{
		incl = it->second->GetObserverNames ( );
	}
	return incl;
}

std::map < std::string , GeoElement * > Model::getElements ( std::set < std::string > & elements )
{
	std::map < std::string , GeoElement * > elts;
	for ( std::set < std::string >::iterator it = elements.begin ( ) ; it != elements.end ( ) ;
		it++ )
	{
		std::map < std::string , GeoElement * >::iterator it2 = m_elements.find ( *it );
		if ( it2 != m_elements.end ( ) )
		{
			elts [ it2->first ] = it2->second;
		}
	}
	return elts;
}
