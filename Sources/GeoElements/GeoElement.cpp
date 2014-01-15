#include "GeoElement.h"

GeoElement::GeoElement ( std::string element ) :
	m_name ( element )
{
}

GeoElement::~GeoElement ( )
{
	Notify ( m_name );
}

std::string GeoElement::GetNom ( )
{
	return m_name;
}
