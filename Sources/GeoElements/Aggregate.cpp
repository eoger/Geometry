#include "Aggregate.h"

#include <sstream>

Aggregate::Aggregate ( std::string element , std::map < std::string , GeoElement * > & elements ) :
	GeoElement ( element ), m_elements ( elements )
{
	for ( std::map < std::string , GeoElement * >::iterator it = m_elements.begin ( ) ;
		it != m_elements.end ( ) ; ++it )
	{
		it->second->AddObserver ( m_name , this );
	}
}

Aggregate::~Aggregate ( )
{
	for ( std::map < std::string , GeoElement * >::iterator it = m_elements.begin ( ) ;
		it != m_elements.end ( ) ; ++it )
	{
		it->second->RemoveObserver ( m_name );
	}
}

std::map < std::string , GeoElement * > Aggregate::GetElements ( )
{
	return m_elements;
}

void Aggregate::Move ( long x , long y )
{
	std::set < GeoElement * > elements;
	GetBasicElements ( elements );
	for ( std::set < GeoElement * >::iterator it = elements.begin ( ) ;
		it != elements.end ( ) ; ++it )
	{
		( *it )->Move ( x , y );
	}
}

std::string Aggregate::Description ( )
{
	std::stringstream str;
	str << "OA " << m_name;
	for ( std::map < std::string , GeoElement * >::iterator it = m_elements.begin ( ) ;
		it != m_elements.end ( ) ; ++it )
	{
		GeoElement * el = it->second;
		str << " " << el->GetNom ( );
	}
	return str.str ( );
}

bool Aggregate::AddElement ( GeoElement * elt )
{
	std::string name = elt->GetNom ( );
	std::map < std::string , GeoElement * >::iterator it = m_elements.find ( name );
	if ( it != m_elements.end ( ) )
	{
		return false;
	}
	else
	{
		m_elements [ name ] = elt;
		return true;
	}
}

void Aggregate::GetBasicElements ( std::set < GeoElement * > & visited )
{
	for ( std::map < std::string , GeoElement * >::iterator it = m_elements.begin ( ) ;
		it != m_elements.end ( ) ; ++it )
	{
		GeoElement * el = it->second;
		if ( Aggregate *pAggregate = dynamic_cast < Aggregate* > ( el ) )
		{
			pAggregate->GetBasicElements ( visited );
		}
		else
		{
			visited.insert ( el );
		}
	}
}

void Aggregate::Update ( std::string name )
{
	std::map < std::string , GeoElement * >::iterator it = m_elements.find ( name );
	if ( it != m_elements.end ( ) )
	{
		m_elements.erase ( it );
	}
}
