#ifndef MOVECOMMAND_H_
#define MOVECOMMAND_H_

class Geometry;
class Model;

#include <string>
#include "Command.h"



class MoveCommand : public Command
{
public:
	MoveCommand ( Geometry * geometry , std::string element , long x , long y );
	virtual ~MoveCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_name;
	long m_x;
	long m_y;
};

#endif /* MOVECOMMAND_H_ */
