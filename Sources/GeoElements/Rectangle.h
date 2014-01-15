#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "GeoElement.h"
#include "Point.h"

class Rectangle : public GeoElement
{
public:
	Rectangle ( std::string element , long x1 , long y1 , long x2 , long y2 );
	virtual ~Rectangle ( );
	virtual void Move ( long x , long y );
	virtual std::string Description ( );

protected:
	Point m_p1;
	Point m_p2;
};

#endif /* RECTANGLE_H_ */
