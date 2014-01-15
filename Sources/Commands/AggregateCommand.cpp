#include "AggregateCommand.h"

#include "../Geometry.h"
#include "../Model.h"

AggregateCommand::AggregateCommand ( Geometry * geometry , std::string element ,
	std::set < std::string > elements ) :
	Command ( geometry ), m_name ( element ), m_elements ( elements )
{
}

AggregateCommand::~AggregateCommand ( )
{
}

bool AggregateCommand::Execute ( Model * model )
{
	return model->CreateAggregate ( m_name , m_elements );
}

void AggregateCommand::Undo ( Model * model )
{
	model->DeleteElement ( m_name );
}
