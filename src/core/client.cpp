#include "client.hpp"
//
#include <auxiliary.hpp>
#include <core/server.hpp>
#include <data/outputData.hpp>
#include <data/inputData.hpp>

Client::Client()
{
	aux::setTransformable( *dynamic_cast< SFMLAdapter* >( this ), mDataset.getConfig< LPP::Table >( "transform" ));
}

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
	SFMLAdapter::getView().setCenter( outputData.viewPosition );
	SFMLAdapter::getView().zoom( outputData.zoom );
	if( !SFMLAdapter::isRunning())
	{
		const LPP::Table* graphicSettings = mDataset.getConfig< LPP::Table >( "graphicSettings" );
		SFMLAdapter::openWindow(
			aux::tableToSize( graphicSettings->at< LPP::Table >( "size" )),
			*graphicSettings->at< LPP::String >( "title" ),
			*graphicSettings->at< LPP::Number >( "fpsLimit" ),
			*graphicSettings->at< LPP::Number >( "vsync" ),
			*graphicSettings->at< LPP::Number >( "antialiasingLevel" ));
	}
	render( outputData );
	update();
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
	for( auto& iEntity : outputData.entities )
	{
		SFMLAdapter::draw( iEntity );
	}
}
