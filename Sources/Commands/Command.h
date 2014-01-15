#ifndef COMMAND_H_
#define COMMAND_H_

class Geometry;
class Model;

class Command
{
public:
	Command ( Geometry * geometry );
	virtual ~Command ( );
	virtual bool Execute ( Model * model ) = 0;
	virtual void Undo ( Model * model ) = 0;
protected:
	Geometry * m_geometry;
};

#endif /* COMMAND_H_ */
