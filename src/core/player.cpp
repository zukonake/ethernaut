#include "player.hpp"
//
#include <data/inputData.hpp>
#include <auxiliary.hpp>

Player::Player( const Dataset& dataset, const Point& position, World& world ) :
	mDataset( dataset ),
	mWorld( world ),
	mEntity( &world.getEntities()[ 0 ])
{

}

OutputData Player::requestOutputData() noexcept
{
	handleKeyStates();
	OutputData returnValue = mOutputData;
	returnValue.entities = mWorld.getEntities();
	returnValue.viewPosition = mEntity->getPosition();
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

			case sf::Event::KeyPressed:
				handleKeys( iEvent, true );
				break;

			case sf::Event::KeyReleased:
				handleKeys( iEvent, false );
				break;

			default:
				break;
		}
	}
}

void Player::handleKeys( sf::Event event, bool pressed )
{
	switch( event.key.code )
	{
		case sf::Keyboard::Escape:
			if( pressed )
			{
				mOutputData.end = true;
			}
			break;

		case sf::Keyboard::W:
			mKeyStates.w = pressed;
			break;

		case sf::Keyboard::A:
			mKeyStates.a = pressed;
			break;

		case sf::Keyboard::S:
			mKeyStates.s = pressed;
			break;

		case sf::Keyboard::D:
			mKeyStates.d = pressed;
			break;

		case sf::Keyboard::Q:
			if( pressed )
			{
				mOutputData.zoom += 0.01;
			}
			break;

		case sf::Keyboard::E:
			if( pressed )
			{
				mOutputData.zoom -= 0.01;
			}
			break;

		default:
			break;
	}
}

void Player::handleKeyStates()
{
	if( mEntity != nullptr )
	{
		if( mKeyStates.w )
		{
			mEntity->addVelocity({ 0, -0.3 });
		}
		if( mKeyStates.a )
		{
			mEntity->rotate( -3 );
		}
		if( mKeyStates.s )
		{
			mEntity->addVelocity({ 0, 0.3 });
		}
		if( mKeyStates.d )
		{
			mEntity->rotate( 3 );
		}
	}
}
