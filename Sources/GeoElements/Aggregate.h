#ifndef AGGREGATE_H_
#define AGGREGATE_H_

#include <map>
#include <set>
#include <vector>
#include <string>

#include "GeoElement.h"
#include "../Observer.h"



class Aggregate : public GeoElement ,
	public Observer
{
public:
	Aggregate ( std::string element ,
		std::map < std::string , GeoElement * > & elements );
	virtual ~Aggregate ( );
	virtual void Move ( long x , long y );
	virtual std::string Description ( );
	std::map < std::string , GeoElement * > GetElements ( );
	bool AddElement ( GeoElement * elt );

	virtual void Update ( std::string data );
protected:
	std::map < std::string , GeoElement * > m_elements;
	std::vector < GeoElement * > GetBasicElements ( );
};

#endif /* AGGREGATE_H_ */
