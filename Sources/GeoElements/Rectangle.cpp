#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle ( std::string element , long x1 , long y1 , long x2 , long y2 ) :
	GeoElement ( element ), m_p1 ( x1 , y1 ), m_p2 ( x2 , y2 )
{
}

Rectangle::~Rectangle ( )
{
}

void Rectangle::Move ( long x , long y )
{
	m_p1.Move ( x , y );
	m_p2.Move ( x , y );
}

std::string Rectangle::Description ( )
{
	std::stringstream str;
	str << "R " << m_name << " " << m_p1.GetX ( ) << " " << m_p1.GetY ( ) << " "
		<< m_p2.GetX ( ) << " " << m_p2.GetY ( );
	
	return str.str ( );
}
