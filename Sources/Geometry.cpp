#include "Geometry.h"

#include <boost/regex.hpp>
#include <exception>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

#include "Commands/AggregateCommand.h"
#include "Commands/CircleCommand.h"
#include "Commands/LineCommand.h"
#include "Commands/LoadCommand.h"
#include "Commands/MoveCommand.h"
#include "Commands/PolylineCommand.h"
#include "Commands/RectangleCommand.h"
#include "Commands/DeleteCommand.h"
#include "Commands/SaveCommand.h"
#include "Commands/ClearCommand.h"
#include "GeoElements/Line.h"
#include "Model.h"
#include "CommandInvoker.h"
#include "Utility.h"



Geometry::Geometry ( )
{
	m_model = new Model ( );
	m_invoker = new CommandInvoker ( m_model );
}

Geometry::~Geometry ( )
{
	delete m_model;
	delete m_invoker;
}

int Geometry::Parse ( std::string cmd , bool storeCmd )
{
	
	int result = CMD_ERR;
	
	boost::smatch matches;
	boost::regex regex (
		"^((?:C|R|L|PL|OA|DELETE|MOVE|LOAD|SAVE) |(?:LIST|UNDO|REDO|CLEAR|#)$)" );

	if ( cmd == "" )
	{
		return CMD_VOID;
	}
	
	if ( !boost::regex_search ( cmd , matches , regex ) )
	{
		return result;
	}
	
	std::string prefix = matches [ 1 ];
	
	if ( prefix == "C " )
	{
		result = parseCircle ( cmd , storeCmd );
	}
	else if ( prefix == "R " )
	{
		result = parseRectangle ( cmd , storeCmd );
	}
	else if ( prefix == "L " )
	{
		result = parseLine ( cmd , storeCmd );
	}
	else if ( prefix == "PL " )
	{
		result = parsePolyline ( cmd , storeCmd );
	}
	else if ( prefix == "OA " )
	{
		result = parseAggregate ( cmd , storeCmd );
	}
	else if ( prefix == "DELETE " )
	{
		result = parseDelete ( cmd );
	}
	else if ( prefix == "MOVE " )
	{
		result = parseMove ( cmd );
	}
	else if ( prefix == "LOAD " )
	{
		result = parseLoad ( cmd );
	}
	else if ( prefix == "SAVE " )
	{
		result = parseSave ( cmd );
	}
	else if ( prefix == "LIST" )
	{
		result = parseList ( cmd );
	}
	else if ( prefix == "UNDO" )
	{
		result = parseUndo ( cmd );
	}
	else if ( prefix == "REDO" )
	{
		result = parseRedo ( cmd );
	}
	else if ( prefix == "CLEAR" )
	{
		parseClear ( cmd );
		result = CMD_OK;
	}
	
	return result;
}

int Geometry::parseCircle ( std::string cmd , bool storeCmd )
{
	
	boost::smatch matches;
	boost::regex regex (
		"^C ([A-Za-z0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) \\+?([0-9]+) *$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string name = matches [ 1 ];
	long x;
	long y;
	unsigned long radius;
	try
	{
		x = stol ( matches [ 2 ].str ( ) );
		y = stol ( matches [ 3 ].str ( ) );
		radius = stoul ( matches [ 4 ].str ( ) );
	}
	catch ( std::exception & e )
	{
		return CMD_ERR;
	}
	
	Command * command = new CircleCommand ( this , name , x , y , radius );
	
	bool result;
	if ( storeCmd )
	{
		result = m_invoker->Do ( command );
	}
	else
	{
		result = m_invoker->DoAndThrow ( command );
	}
	
	if ( result )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseRectangle ( std::string cmd , bool storeCmd )
{
	boost::smatch matches;
	boost::regex regex (
		"^R ([A-Za-z0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) *$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string name = matches [ 1 ];
	long x1;
	long y1;
	long x2;
	long y2;
	try
	{
		x1 = stol ( matches [ 2 ].str ( ) );
		y1 = stol ( matches [ 3 ].str ( ) );
		x2 = stol ( matches [ 4 ].str ( ) );
		y2 = stol ( matches [ 5 ].str ( ) );
	}
	catch ( std::exception & e )
	{
		return CMD_ERR;
	}
	
	Command * command (
		new RectangleCommand ( this , name , x1 , y1 , x2 , y2 ) );
	
	bool result;
	if ( storeCmd )
	{
		result = m_invoker->Do ( command );
	}
	else
	{
		result = m_invoker->DoAndThrow ( command );
	}
	
	if ( result )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseLine ( std::string cmd , bool storeCmd )
{
	boost::smatch matches;
	boost::regex regex (
		"^L ([A-Za-z0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) *$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string name = matches [ 1 ];
	long x1;
	long y1;
	long x2;
	long y2;
	try
	{
		x1 = stol ( matches [ 2 ] );
		y1 = stol ( matches [ 3 ].str ( ) );
		x2 = stol ( matches [ 4 ].str ( ) );
		y2 = stol ( matches [ 5 ].str ( ) );
	}
	catch ( std::exception & e )
	{
		return CMD_ERR;
	}
	
	Command * command = new LineCommand ( this , name , x1 , y1 , x2 , y2 );
	
	bool result;
	if ( storeCmd )
	{
		result = m_invoker->Do ( command );
	}
	else
	{
		result = m_invoker->DoAndThrow ( command );
	}
	
	if ( result )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parsePolyline ( std::string cmd , bool storeCmd )
{
	boost::smatch matches;
	boost::regex regex (
		"^PL ([A-Za-z0-9]+)((?: (?:\\+|-)?[0-9]+ (?:\\+|-)?[0-9]+){2,}) *$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string name = matches [ 1 ];
	std::vector < std::string > submatches = explode ( matches [ 2 ] , ' ' );
	std::vector < Line > lines;
	try
	{
		for ( unsigned int i = 1 ; i < submatches.size ( ) - 2 ; i += 2 )
		{
			long x1 = stol ( submatches [ i ] );
			long y1 = stol ( submatches [ i + 1 ] );
			long x2 = stol ( submatches [ i + 2 ] );
			long y2 = stol ( submatches [ i + 3 ] );
			Line l ( "" , x1 , y1 , x2 , y2 );
			lines.push_back ( l );
		}
	}
	catch ( std::exception & e )
	{
		return CMD_ERR;
	}
	
	Command * command = new PolylineCommand ( this , name , lines );
	
	bool result;
	if ( storeCmd )
	{
		result = m_invoker->Do ( command );
	}
	else
	{
		result = m_invoker->DoAndThrow ( command );
	}
	
	if ( result )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseAggregate ( std::string cmd , bool storeCmd )
{
	boost::smatch matches;
	boost::regex regex ( "^OA ([A-Za-z0-9]+)((?: [A-Za-z0-9]+)*) *$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string name = matches [ 1 ];
	std::vector < std::string > submatches = explode ( matches [ 2 ] , ' ' );
	std::set < std::string > elements;
	
	for ( unsigned int i = 1 ; i < submatches.size ( ) ; i++ )
	{
		elements.insert ( submatches [ i ] );
	}
	
	Command * command = new AggregateCommand ( this , name , elements );
	
	bool result;
	if ( storeCmd )
	{
		result = m_invoker->Do ( command );
	}
	else
	{
		result = m_invoker->DoAndThrow ( command );
	}
	
	if ( result )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseDelete ( std::string cmd )
{
	boost::smatch matches;
	boost::regex regex ( "^DELETE((?: [A-Za-z0-9]+)+) *$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::vector < std::string > submatches = explode ( matches [ 1 ] , ' ' );
	std::set < std::string > elements;
	
	for ( unsigned int i = 1 ; i < submatches.size ( ) ; i++ )
	{
		elements.insert ( submatches [ i ] );
	}
	
	Command * command = new DeleteCommand ( this , elements );
	if ( m_invoker->Do ( command ) )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseMove ( std::string cmd )
{
	boost::smatch matches;
	boost::regex regex (
		"^MOVE ([A-Za-z0-9]+) ((?:\\+|-)?[0-9]+) ((?:\\+|-)?[0-9]+) *$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string element = matches [ 1 ];
	long x;
	long y;
	try
	{
		x = stol ( matches [ 2 ].str ( ) );
		y = stol ( matches [ 3 ].str ( ) );
	}
	catch ( std::exception & e )
	{
		return CMD_ERR;
	}
	
	Command * command = new MoveCommand ( this , element , x , y );
	if ( m_invoker->Do ( command ) )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseList ( std::string cmd )
{
	std::cout << m_model->Description ( );
	return CMD_VOID;
}

int Geometry::parseUndo ( std::string cmd )
{
	if ( m_invoker->Undo ( ) )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseRedo ( std::string cmd )
{
	if ( m_invoker->Redo ( ) )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseLoad ( std::string cmd )
{
	boost::smatch matches;
	boost::regex regex ( "^LOAD ([^\\0]+)$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string filename = matches [ 1 ];
	
	Command * command = new LoadCommand ( this , filename );
	if ( m_invoker->Do ( command ) )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
}

int Geometry::parseSave ( std::string cmd )
{
	boost::smatch matches;
	boost::regex regex ( "^SAVE ([^\\0]+)$" );
	
	if ( !boost::regex_match ( cmd , matches , regex ) )
	{
		return CMD_ERR;
	}
	
	std::string filename = matches [ 1 ];
	
	Command * command = new SaveCommand ( this , matches [ 1 ] );
	if ( m_invoker->DoAndThrow ( command ) )
	{
		return CMD_OK;
	}
	else
	{
		return CMD_ERR;
	}
	
}

void Geometry::parseClear ( std::string cmd )
{
	Command * command = new ClearCommand ( this );
	m_invoker->Do ( command );
}

int main ( int argc , char ** argv )
{
	Geometry c;
	std::string cmd;
	while ( true )
	{
		getline ( std::cin , cmd );
		if ( cmd == "EXIT" )
		{
			break;
		}
		int result = c.Parse ( cmd , true );
		if ( CMD_OK == result )
		{
			std::cout << "OK" << std::endl;
		}
		else if ( CMD_ERR == result )
		{
			std::cout << "ERR" << std::endl;
		}
	}
	return 0;
}
