#ifndef MODEL_H_
#define MODEL_H_

#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "GeoElements/Line.h"
#include "Utility.h"



class Model
{
public:
	Model ( );
	virtual ~Model ( );

	bool CreateAggregate ( std::string element , std::set < std::string > & elements );
	bool CreateCircle ( std::string element , long x1 , long y1 , unsigned long radius );
	bool CreateLine ( std::string element , long x1 , long y1 , long x2 , long y2 );
	bool CreatePolyline ( std::string element , std::vector < Line > lines );
	bool CreateRectangle ( std::string element , long x1 , long y1 , long x2 , long y2 );

	bool AddToAggregate ( std::string nameObj , std::string nameAggregate );

	std::vector < std::string > GetInclusions ( std::string element );

	bool Move ( std::string element , long x , long y );
	bool DeleteElement ( std::string element );

	std::string Description ( );
	std::string DescriptionSerialized ( );

	std::string Description ( std::string element );
	void Clear ( );

protected:
	std::map < std::string , GeoElement * , ::cmp_no_uppercase > m_elements;

	std::map < std::string , GeoElement * > getElements ( std::set < std::string > & elements );

	template < typename T >
	std::string descriptionSerialized ( std::map < std::string , GeoElement * , T > elements ,
		std::vector < std::string > & visited );
};

#endif /* MODEL_H_ */
