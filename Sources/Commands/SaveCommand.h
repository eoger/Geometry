#ifndef SAVECOMMAND_H_
#define SAVECOMMAND_H_

class Geometry;
class Model;

#include <string>
#include "Command.h"



class SaveCommand : public Command
{
public:
	SaveCommand ( Geometry * geometry , std::string filename );
	virtual ~SaveCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_filename;
};

#endif /* SAVECOMMAND_H_ */
