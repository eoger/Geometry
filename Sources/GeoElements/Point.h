#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
	Point ( long x , long y );
	virtual ~Point ( );

	long GetX ( );
	long GetY ( );
	void Move ( long x , long y );

protected:
	long m_x;
	long m_y;
};

#endif /* POINT_H_ */
