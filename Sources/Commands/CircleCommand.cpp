#include "CircleCommand.h"

#include "../Geometry.h"
#include "../Model.h"

CircleCommand::CircleCommand ( Geometry * geometry , std::string element , long x ,
	long y , unsigned long radius ) :
	Command ( geometry ), m_name ( element ), m_x ( x ), m_y ( y ), m_radius (
		radius )
{
}

CircleCommand::~CircleCommand ( )
{
}

bool CircleCommand::Execute ( Model * model )
{
	return model->CreateCircle ( m_name , m_x , m_y , m_radius );
}

void CircleCommand::Undo ( Model * model )
{
	model->DeleteElement ( m_name );
}
