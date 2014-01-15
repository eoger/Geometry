#ifndef LINE_H_
#define LINE_H_

#include "GeoElement.h"
#include "Point.h"

class Line : public GeoElement
{
public:
	Line ( std::string element , long x1 , long y1 , long x2 , long y2 );
	virtual ~Line ( );
	virtual void Move ( long x , long y );
	virtual std::string Description ( );
	Point GetPoint1 ( );
	Point GetPoint2 ( );
protected:
	Point m_p1;
	Point m_p2;
};

#endif /* LINE_H_ */
