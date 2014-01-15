#include "Observable.h"

void Observable::Notify ( std::string data )
{
	for ( std::map < std::string , Observer* >::iterator it = m_observers.begin ( ) ;
		it != m_observers.end ( ) ; ++it )
	{
		it->second->Update ( data );
	}
}

void Observable::AddObserver ( std::string name , Observer* observer )
{
	m_observers [ name ] = observer;
}

void Observable::RemoveObserver ( std::string name )
{
	m_observers.erase ( name );
}

std::vector < std::string > Observable::GetObserverNames ( )
{
	std::vector < std::string > names;
	
	for ( std::map < std::string , Observer* >::iterator it = m_observers.begin ( ) ;
		it != m_observers.end ( ) ; ++it )
	{
		names.push_back ( it->first );
	}
	return names;
}
