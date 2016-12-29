#include "client.hpp"
//
#include <core/server.hpp>
#include <core/outputData.hpp>
#include <core/inputData.hpp>

Client::~Client()
{
	disconnect();
}

InputData Client::requestInputData() noexcept
{
	InputData returnValue;
	returnValue.events = SFMLAdapter::getEvents();
	return returnValue;
}

void Client::receiveOutputData( OutputData outputData ) noexcept
{
	if( outputData.end == true )
	{
		disconnect();
		return;
	}
	if( !SFMLAdapter::isRunning())
	{
		SFMLAdapter::openWindow( outputData.windowSize, outputData.windowTitle );
	}
	render( outputData );
}

void Client::connect( Server* server )
{
	if( !isConnected() )
	{
		mServer = server;
		mServer->connect( this );
	}
}

void Client::disconnect()
{
	if( isConnected() )
	{
		mServer->disconnect( this );
		mServer = nullptr;
	}
}

bool Client::isConnected() const noexcept
{
	return mServer != nullptr;
}

void Client::render( const OutputData& outputData )
{
	//TODO
}
