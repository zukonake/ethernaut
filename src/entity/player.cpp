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
	returnValue.entities.emplace_back( mDataset.getObject< EntitySubtype >( "scout" ));
	returnValue.entities[0].mTransform.translate( 15, 15 );
	returnValue.windowSize = conversion::tableToSize( mDataset.getConfig< LPP::Table >( "windowSize" ));
	returnValue.windowTitle = *mDataset.getConfig< LPP::String >( "windowTitle" );
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
