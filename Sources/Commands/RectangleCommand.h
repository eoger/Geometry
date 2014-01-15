#ifndef RECTANGLECOMMAND_H_
#define RECTANGLECOMMAND_H_

class Geometry;
class Model;

#include <string>
#include "Command.h"



class RectangleCommand : public Command
{
public:
	RectangleCommand ( Geometry * geometry , std::string element , long x1 ,
		long y1 , long x2 , long y2 );
	virtual ~RectangleCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_name;
	long m_x1;
	long m_y1;
	long m_x2;
	long m_y2;
};

#endif /* RECTANGLECOMMAND_H_ */
