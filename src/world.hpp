#ifndef WORLD_HPP
#define WORLD_HPP

#include <core/dataset.hpp>
#include <entity/entity.hpp>

class World
{
public:
	World( const Dataset& dataset );
private:
	std::vector< Entity > mEntities;
};

#endif
