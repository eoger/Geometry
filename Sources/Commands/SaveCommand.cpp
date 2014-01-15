#include "SaveCommand.h"
#include <fstream>
#include <boost/regex.hpp>

#include "../Geometry.h"
#include "../Model.h"

SaveCommand::SaveCommand ( Geometry * geometry , std::string filename ) :
	Command ( geometry ), m_filename ( filename )
{
}

SaveCommand::~SaveCommand ( )
{
}

bool SaveCommand::Execute ( Model * model )
{
	std::string desc = model->DescriptionSerialized ( );
	
	std::ofstream sortie ( m_filename.c_str ( ) );
	if ( !sortie )
	{
		return false;
	}
	
	sortie << desc;
	
	return sortie.good ( );
}

void SaveCommand::Undo ( Model * model )
{
}
