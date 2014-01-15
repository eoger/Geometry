#ifndef GEOELEMENT_H_
#define GEOELEMENT_H_

#include <string>
#include "../Observable.h"



class GeoElement : public Observable
{
public:
	GeoElement ( std::string element );
	virtual ~GeoElement ( );
	virtual void Move ( long x , long y )=0;
	virtual std::string Description ( )=0;
	std::string GetNom ( );
protected:
	std::string m_name;
};

#endif /* GEOELEMENT_H_ */
