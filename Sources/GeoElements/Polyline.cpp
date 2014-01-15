#include "Polyline.h"
#include <sstream>

Polyline::Polyline ( std::string element , std::vector < Line > & lines ) :
	GeoElement ( element ), m_outline ( lines )
{
}

Polyline::~Polyline ( )
{
}

void Polyline::Move ( long x , long y )
{
	for ( unsigned int i = 0 ; i < m_outline.size ( ) ; i++ )
	{
		m_outline [ i ].Move ( x , y );
	}
}
std::string Polyline::Description ( )
{
	
	std::stringstream str;
	str << "PL " << m_name;
	
	size_t i;
	for ( i = 0; i < m_outline.size ( ) - 1 ; i++ )
	{
		Point p = m_outline [ i ].GetPoint1 ( );
		str << " " << p.GetX ( ) << " " << p.GetY ( );
	}
	Point p1 = m_outline [ i ].GetPoint1 ( );
	Point p2 = m_outline [ i ].GetPoint2 ( );
	str << " " << p1.GetX ( ) << " " << p1.GetY ( ) << " " << p2.GetX ( ) << " "
		<< p2.GetY ( );
	return str.str ( );
}
