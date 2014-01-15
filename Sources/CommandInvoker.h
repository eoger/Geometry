#ifndef COMMANDINVOKER_H_
#define COMMANDINVOKER_H_

class Model;
class Command;

#include <stack>



class CommandInvoker
{
public:
	CommandInvoker ( Model * model );
	virtual ~CommandInvoker ( );

	bool Do ( Command *cmd );
	bool DoAndThrow ( Command * cmd );
	bool Undo ( );
	bool Redo ( );

protected:
	Model * m_model;
	std::stack < Command * > m_undo;
	std::stack < Command * > m_redo;
};

#endif /* COMMANDINVOKER_H_ */
