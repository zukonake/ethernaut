#include "server.hpp"
//
#include <core/client.hpp>
#include <entity/player.hpp>
#include <core/inputData.hpp>

Server::Server() :
	mWorld( mDataset )
{

}

Server::~Server()
{
	for( auto& iPair : mClients )
	{
		iPair.second->disconnect();
	}
}

void Server::loop()
{
	for( auto& iPair : mClients )
	{
		iPair.first.receiveInputData( iPair.second->requestInputData() );
		iPair.second->receiveOutputData( iPair.first.requestOutputData() );
	}
	//TODO simulations
}

void Server::connect( Client* client )
{
	mClients.push_back( std::pair< Player, Client* >( Player( mDataset, { 0, 0 }, &mWorld ), client ) ); //TODO assign world
}

void Server::disconnect( Client* client )
{
	//auto iClient = std::find_if( mClients.begin(), mClients.end(),TODO
	//[ client ]( std::pair< Player, Client* > pair )->bool { return pair.second == client; });
	//mClients.erase( iClient );
}
