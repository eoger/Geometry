#ifndef CIRCLECOMMAND_H_
#define CIRCLECOMMAND_H_

class Geometry;
class Model;

#include <string>

#include "Command.h"



class CircleCommand : public Command
{
public:
	CircleCommand ( Geometry * geometry , std::string element , long x , long y ,
		unsigned long radius );
	virtual ~CircleCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_name;
	long m_x;
	long m_y;
	unsigned long m_radius;
};

#endif /* CIRCLECOMMAND_H_ */
