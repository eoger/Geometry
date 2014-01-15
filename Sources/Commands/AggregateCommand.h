#ifndef AGGREGATECOMMAND_H_
#define AGGREGATECOMMAND_H_

class Geometry;
class Model;

#include <string>
#include <set>

#include "Command.h"



class AggregateCommand : public Command
{
public:
	AggregateCommand ( Geometry * geometry , std::string element ,
		std::set < std::string > elements );
	virtual ~AggregateCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_name;
	std::set < std::string > m_elements;
};

#endif /* AGGREGATECOMMAND_H_ */
