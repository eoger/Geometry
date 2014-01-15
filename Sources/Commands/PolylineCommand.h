#ifndef POLYLINECOMMAND_H_
#define POLYLINECOMMAND_H_

class Geometry;
class Model;

#include <string>
#include "Command.h"
#include "../GeoElements/Line.h"



class PolylineCommand : public Command
{
public:
	PolylineCommand ( Geometry * geometry , std::string element ,
		std::vector < Line > lines );
	virtual ~PolylineCommand ( );
	virtual bool Execute ( Model * model );
	virtual void Undo ( Model * model );
protected:
	std::string m_name;
	std::vector < Line > m_lines;
};

#endif /* POLYLINECOMMAND_H_ */
