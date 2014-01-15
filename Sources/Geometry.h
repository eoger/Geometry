#ifndef GEOMETRY_H_
#define GEOMETRY_H_

class Model;
class CommandInvoker;

#include <string>

#define CMD_OK 0
#define CMD_ERR 1
#define CMD_VOID 2



class Geometry
{
public:
	Geometry ( );
	virtual ~Geometry ( );
	int Parse ( std::string cmd , bool storeCmd );

protected:
	int parseCircle ( std::string cmd , bool storeCmd );
	int parseRectangle ( std::string cmd , bool storeCmd );
	int parseLine ( std::string cmd , bool storeCmd );
	int parsePolyline ( std::string cmd , bool storeCmd );
	int parseAggregate ( std::string cmd , bool storeCmd );
	int parseDelete ( std::string cmd );
	int parseMove ( std::string cmd );
	int parseList ( std::string cmd );
	int parseUndo ( std::string cmd );
	int parseRedo ( std::string cmd );
	int parseLoad ( std::string cmd );
	int parseSave ( std::string cmd );
	void parseClear ( std::string cmd );

	Model * m_model;
	CommandInvoker * m_invoker;
};

int main ( int argc , char ** argv );

#endif /* GEOMETRY_H_ */
