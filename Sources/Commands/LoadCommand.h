#ifndef LOADCOMMAND_H_
#define LOADCOMMAND_H_

class Geometry;
class Model;

#include <string>
#include <vector>
#include "Command.h"



class LoadCommand : public Command
{
public:
	LoadCommand ( Geometry * geometry , std::string filename );
	virtual ~LoadCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_filename;
	std::vector < std::string > m_objs;
};

#endif /* LOADCOMMAND_H_ */
