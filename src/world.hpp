#ifndef WORLD_HPP
#define WORLD_HPP

#include <entity/entity.hpp>

class Dataset;

class World
{
public:
	World( const Dataset& dataset );

	void simulate();

	std::vector< Entity >& getEntities() noexcept;
private:
	const Dataset& mDataset;
	std::vector< Entity > mEntities;
};

#endif
