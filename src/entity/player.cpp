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
	OutputData returnValue;
	//returnValue.entities.push_back( mDataset.getObject< Part >( "hullSquare" )); //TODO
	returnValue.windowSize = conversion::tableToSize( mDataset.getConfig< LPP::Table >( "windowSize" ));
	returnValue.windowTitle = *mDataset.getConfig< LPP::String >( "windowTitle" );
	return returnValue;
}

void Player::receiveInputData( InputData inputData ) noexcept
{

}
