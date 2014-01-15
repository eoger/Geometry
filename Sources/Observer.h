#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>
#include <set>
#include <iostream>


class Observer
{
public:
	virtual ~Observer ( )
	{
	}
	virtual void Update ( std::string data ) = 0;
};

#endif /* OBSERVER_H_ */
