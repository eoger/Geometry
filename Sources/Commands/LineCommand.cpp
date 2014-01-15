#include "LineCommand.h"

#include "../Geometry.h"
#include "../Model.h"

LineCommand::LineCommand ( Geometry * geometry , std::string name , long x1 ,
	long y1 , long x2 , long y2 ) :
	Command ( geometry ), m_name ( name ), m_x1 ( x1 ), m_y1 ( y1 ), m_x2 ( x2 ), m_y2 (
		y2 )
{
	
}

LineCommand::~LineCommand ( )
{
}

bool LineCommand::Execute ( Model * model )
{
	return model->CreateLine ( m_name , m_x1 , m_y1 , m_x2 , m_y2 );
}

void LineCommand::Undo ( Model * model )
{
	model->DeleteElement ( m_name );
}

