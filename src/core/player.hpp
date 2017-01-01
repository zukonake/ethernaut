#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <typedef.hpp>
#include <data/keyStates.hpp>
#include <data/outputData.hpp>
#include <world.hpp>

struct InputData;
class Dataset;

class Player
{
public:
	Player( const Dataset& dataset, const Point& position, World& world );

	OutputData requestOutputData() noexcept;
	void receiveInputData( InputData inputData ) noexcept;
private:
	void handleKeys( sf::Event event, bool pressed = true );
	void handleKeyStates();

	const Dataset& mDataset;
	World& mWorld;
	Entity* mEntity = nullptr;
	KeyStates mKeyStates;
	OutputData mOutputData;
};

#endif
