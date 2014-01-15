#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "GeoElement.h"
#include "Point.h"

class Circle : public GeoElement
{
public:
	Circle ( std::string element , long x , long y , unsigned long radius );
	virtual ~Circle ( );
	virtual void Move ( long x , long y );
	virtual std::string Description ( );

protected:
	Point m_center;
	unsigned long m_radius;
};

#endif /* CIRCLE_H_ */
