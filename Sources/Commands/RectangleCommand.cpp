#include "RectangleCommand.h"

#include "../Geometry.h"
#include "../Model.h"

RectangleCommand::RectangleCommand ( Geometry * geometry , std::string element ,
	long x1 , long y1 , long x2 , long y2 ) :
	Command ( geometry ), m_name ( element ), m_x1 ( x1 ), m_y1 ( y1 ), m_x2 (
		x2 ), m_y2 ( y2 )
{
}

RectangleCommand::~RectangleCommand ( )
{
}

bool RectangleCommand::Execute ( Model * model )
{
	return model->CreateRectangle ( m_name , m_x1 , m_y1 , m_x2 , m_y2 );
}

void RectangleCommand::Undo ( Model * model )
{
	model->DeleteElement ( m_name );
}
