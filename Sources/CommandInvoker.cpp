#include "CommandInvoker.h"

#include "Model.h"
#include "Commands/Command.h"

CommandInvoker::CommandInvoker ( Model * model ) :
	m_model ( model )
{
	
}

CommandInvoker::~CommandInvoker ( )
{
	while ( !m_redo.empty ( ) )
	{
		Command * cmd = m_redo.top ( );
		m_redo.pop ( );
		delete cmd;
	}
	while ( !m_undo.empty ( ) )
	{
		Command * cmd = m_undo.top ( );
		m_undo.pop ( );
		delete cmd;
	}
}

bool CommandInvoker::Do ( Command * cmd )
{
	if ( cmd->Execute ( m_model ) )
	{
		m_undo.push ( cmd );
		while ( !m_redo.empty ( ) )
		{
			Command * cmd = m_redo.top ( );
			m_redo.pop ( );
			delete cmd;
		}
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CommandInvoker::DoAndThrow ( Command * cmd )
{
	return cmd->Execute ( m_model );
}

bool CommandInvoker::Undo ( )
{
	if ( m_undo.size ( ) == 0 )
	{
		return false;
	}
	else
	{
		Command * undo = m_undo.top ( );
		m_undo.pop ( );
		undo->Undo ( m_model );
		m_redo.push ( undo );
		return true;
	}
}
bool CommandInvoker::Redo ( )
{
	if ( m_redo.size ( ) == 0 )
	{
		return false;
	}
	else
	{
		Command * redo = m_redo.top ( );
		m_redo.pop ( );
		redo->Execute ( m_model );
		m_undo.push ( redo );
		return true;
	}
}
