#include "player.hpp"
//
#include <core/inputData.hpp>
#include <conversion.hpp>

Player::Player( const Dataset& dataset, const Point& position, World* world ) :
	mDataset( dataset )
{

}

OutputData Player::requestOutputData() noexcept
{
	OutputData returnValue = mOutputData;
	returnValue.entities.emplace_back( mDataset.getObject< EntitySubtype >( "testVehicle" ));
	returnValue.entities[0].mTransform.translate( 150, 150 );
	return returnValue;
}

void Player::receiveInputData( InputData inputData ) noexcept
{
	for( auto iEvent : inputData.events )
	{
		switch( iEvent.type )
		{
			case sf::Event::Closed:
				mOutputData.end = true;
				break;
			default:
				break;
		}
	}
}
