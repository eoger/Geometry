#include "Point.h"

Point::Point ( long x , long y ) :
	m_x ( x ), m_y ( y )
{
}

Point::~Point ( )
{
}

void Point::Move ( long x , long y )
{
	m_x += x;
	m_y += y;
}

long Point::GetX ( )
{
	return m_x;
}
long Point::GetY ( )
{
	return m_y;
}
