#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <string>
#include <map>
#include <vector>

#include "Observer.h"



class Observable
{
	
public:
	void Notify ( std::string data );
	void AddObserver ( std::string name , Observer* observer );
	void RemoveObserver ( std::string name );
	std::vector < std::string > GetObserverNames ( );

protected:
	std::map < std::string , Observer* > m_observers;
};

#endif /* OBSERVABLE_H_ */
