#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <typedef.hpp>
#include <core/outputData.hpp>
#include <world.hpp>

struct InputData;
class Dataset;

class Player
{
public:
	Player( const Dataset& dataset, const Point& position, World* world );

	OutputData requestOutputData() noexcept;
	void receiveInputData( InputData inputData ) noexcept;
};

#endif
