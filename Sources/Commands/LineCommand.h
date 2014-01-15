#ifndef LINECOMMAND_H_
#define LINECOMMAND_H_

class Geometry;
class Model;

#include "Command.h"
#include <string>



class LineCommand : public Command
{
public:
	LineCommand ( Geometry * geometry , std::string name , long x1 , long y1 ,
		long x2 , long y2 );
	virtual ~LineCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_name;
	long m_x1;
	long m_y1;
	long m_x2;
	long m_y2;
};

#endif /* LINECOMMAND_H_ */
