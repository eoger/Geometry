#ifndef DELETECOMMAND_H_
#define DELETECOMMAND_H_

class Geometry;
class Model;

#include <string>
#include <map>
#include <set>
#include <vector>
#include "Command.h"



class DeleteCommand : public Command
{
public:
	DeleteCommand ( Geometry * geometry , std::set < std::string > & elements );
	virtual ~DeleteCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::set < std::string > m_elements;
	std::map < std::string , std::vector < std::string > > m_deletedObjs;
};

#endif /* DELETECOMMAND_H_ */
