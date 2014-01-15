#ifndef CLEARCOMMAND_H_
#define CLEARCOMMAND_H_

class Geometry;
class Model;

#include <string>

#include "Command.h"



class ClearCommand : public Command
{
public:
	ClearCommand ( Geometry * geometry );
	virtual ~ClearCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_descs;
};

#endif /* CLEARCOMMAND_H_ */
