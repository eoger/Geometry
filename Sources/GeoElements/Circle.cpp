#include "Circle.h"
#include <sstream>

Circle::Circle ( std::string element , long x , long y , unsigned long radius ) :
	GeoElement ( element ), m_center ( x , y ), m_radius ( radius )
{
}

Circle::~Circle ( )
{
}
void Circle::Move ( long x , long y )
{
	m_center.Move ( x , y );
}
std::string Circle::Description ( )
{
	std::stringstream str;
	str << "C " << m_name << " " << m_center.GetX ( ) << " " << m_center.GetY ( )
		<< " " << m_radius;
	
	return str.str ( );
}

