#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>
#include <vector>



std::vector < std::string > explode ( std::string str , char delim );

struct cmp_no_uppercase
{
	bool operator() ( std::string first , std::string second );
};

#endif /* UTILITY_H_ */
