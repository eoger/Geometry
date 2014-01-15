#include "PolylineCommand.h"

#include "../Geometry.h"
#include "../Model.h"

PolylineCommand::PolylineCommand ( Geometry * geometry , std::string element ,
	std::vector < Line > lines ) :
	Command ( geometry ), m_name ( element ), m_lines ( lines )
{
}

PolylineCommand::~PolylineCommand ( )
{
}

bool PolylineCommand::Execute ( Model * model )
{
	return model->CreatePolyline ( m_name , m_lines );
}

void PolylineCommand::Undo ( Model * model )
{
	model->DeleteElement ( m_name );
}
