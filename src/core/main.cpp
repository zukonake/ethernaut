#include <iostream>
//
#include <core/client.hpp>
#include <core/server.hpp>

int main()
{
	Client localClient;
	Server* localServer = new Server();
	localClient.connect( localServer );
	try
	{
		while( localClient.isConnected() )
		{
			localServer->loop();
		}
	}
	catch( std::exception& e )
	{
		std::cerr << e.what() << "\n";
	}
	delete localServer;
	return 0;
}
