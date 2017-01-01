#include "world.hpp"
//
#include <data/dataset.hpp>

World::World( const Dataset& dataset ) :
	mDataset( dataset )
{
	mEntities.emplace_back( mDataset.getObject< EntitySubtype >( "testVehicle" ));
	mEntities[0].move( 150, 150 );
	mEntities[0].rotate( 90 );
	mEntities.emplace_back( mDataset.getObject< EntitySubtype >( "rock" ));
}

void World::simulate()
{
	for( auto& iEntity : mEntities )
	{
		iEntity.simulate();
	}
}

std::vector< Entity >& World::getEntities() noexcept
{
	return mEntities;
}
