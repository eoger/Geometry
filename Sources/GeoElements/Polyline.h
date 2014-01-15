#ifndef POLYLINE_H_
#define POLYLINE_H_
#include "Line.h"

#include <vector>
#include "GeoElement.h"

class Polyline : public GeoElement
{
public:
	Polyline ( std::string element , std::vector < Line > & lines );
	virtual ~Polyline ( );
	virtual void Move ( long x , long y );
	virtual std::string Description ( );

protected:
	std::vector < Line > m_outline;
};

#endif /* POLYLINE_H_ */
