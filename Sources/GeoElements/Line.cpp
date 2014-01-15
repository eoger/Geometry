#include "Line.h"
#include <sstream>

Line::Line ( std::string element , long x1 , long y1 , long x2 , long y2 ) :
	GeoElement ( element ), m_p1 ( x1 , y1 ), m_p2 ( x2 , y2 )
{
}

Line::~Line ( )
{
}

void Line::Move ( long x , long y )
{
	m_p1.Move ( x , y );
	m_p2.Move ( x , y );
}

std::string Line::Description ( )
{
	std::stringstream str;
	str << "L " << m_name << " " << m_p1.GetX ( ) << " " << m_p1.GetY ( ) << " "
		<< m_p2.GetX ( ) << " " << m_p2.GetY ( );
	
	return str.str ( );
}

Point Line::GetPoint1 ( )
{
	return m_p1;
}
Point Line::GetPoint2 ( )
{
	return m_p2;
}
