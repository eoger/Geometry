#include "Utility.h"

#include <sstream>
#include <utility>

std::vector < std::string > explode ( std::string str , char delim )
{
	std::vector < std::string > result;
	std::istringstream iss ( str );
	std::string tok;
	
	while ( getline ( iss , tok , delim ) )
	{
		result.push_back ( tok );
	}
	
	return result;
}

bool cmp_no_uppercase::operator() ( std::string first , std::string second )
{
	unsigned int i = 0;
	while ( ( i < first.length ( ) ) && ( i < second.length ( ) ) )
	{
		if ( tolower ( first [ i ] ) < tolower ( second [ i ] ) )
			return true;
		else if ( tolower ( first [ i ] ) > tolower ( second [ i ] ) )
			return false;
		++i;
	}
	return ( first.length ( ) < second.length ( ) );
}
