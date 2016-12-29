#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <utility>
#include <vector>
//
#include <nonCopyable.hpp>
//
#include <entity/player.hpp>
#include <core/dataset.hpp>
#include <world.hpp>

class Client;

//TODO networking stuff( ip etc. )

class Server : virtual NonCopyable
{
public:
	Server();
	~Server();

	void loop();

	void connect( Client* client );
	void disconnect( Client* client );
private:
	std::vector< std::pair< Player, Client* > > mClients;

	Dataset mDataset;
	World mWorld;
};

#endif
