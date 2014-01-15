#include "ClearCommand.h"
#include <fstream>
#include <boost/regex.hpp>

#include "../Geometry.h"
#include "../Model.h"

ClearCommand::ClearCommand ( Geometry * geometry ) :
	Command ( geometry )
{
}

ClearCommand::~ClearCommand ( )
{
}

bool ClearCommand::Execute ( Model * model )
{
	m_descs = model->DescriptionSerialized ( );
	model->Clear ( );
	return true;
}

void ClearCommand::Undo ( Model * model )
{
	std::istringstream iss ( m_descs );
	while ( !iss.eof ( ) )
	{
		std::string cmd;
		getline ( iss , cmd );
		m_geometry->Parse ( cmd , false );
	}
}
