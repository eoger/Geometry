#include "MoveCommand.h"

#include "../Geometry.h"
#include "../Model.h"

MoveCommand::MoveCommand ( Geometry * geometry , std::string element , long x ,
	long y ) :
	Command ( geometry ), m_name ( element ), m_x ( x ), m_y ( y )
{
}

MoveCommand::~MoveCommand ( )
{
}

bool MoveCommand::Execute ( Model * model )
{
	return model->Move ( m_name , m_x , m_y );
}

void MoveCommand::Undo ( Model * model )
{
	model->Move ( m_name , -m_x , -m_y );
}
