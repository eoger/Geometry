#include "Aggregate.h"

#include <sstream>
#include <set>
#include <stack>

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
	std::vector < GeoElement * > elements = GetBasicElements ( );
	for ( std::vector < GeoElement * >::iterator it = elements.begin ( ) ;
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

std::vector < GeoElement * > Aggregate::GetBasicElements ( )
{
	std::vector < GeoElement * > basicElements;
	std::stack < GeoElement * > toVisit;
	std::set < GeoElement * > visited;

	toVisit.push ( this );

	while ( ! toVisit.empty ( ) )
	{
		GeoElement * el = toVisit.top ( );
		toVisit.pop ( );

		if ( visited.find(el) == visited.end() )
		{
			visited.insert(el);

			if ( Aggregate *pAggregate = dynamic_cast < Aggregate* > ( el ) )
			{
				for ( std::map < std::string , GeoElement * >::iterator it = pAggregate->m_elements.begin ( ) ; 
					it != pAggregate->m_elements.end ( ) ; ++it )
				{
					toVisit.push ( it->second ) ;
				}
			}
			else
			{
				basicElements.push_back ( el );
			}
		}
	}

	return basicElements;
}

void Aggregate::Update ( std::string name )
{
	std::map < std::string , GeoElement * >::iterator it = m_elements.find ( name );
	if ( it != m_elements.end ( ) )
	{
		m_elements.erase ( it );
	}
}
