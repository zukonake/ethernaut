#include "SFMLAdapter.hpp"
//
#include <iostream>
#include <exception>

SFMLAdapter::~SFMLAdapter() noexcept
{
	mWindow.close();
}

void SFMLAdapter::update() noexcept
{
	mWindow.display();
	mWindow.clear( sf::Color::Black );
}

void SFMLAdapter::draw( const sf::Drawable& drawable, sf::RenderStates states )
{
	states.transform.combine( mTransform );
	mWindow.draw( drawable, states );
}

void SFMLAdapter::openWindow( const Size& windowSize, const std::string& windowTitle, uint8_t fpsLimit, bool vsync, uint8_t antialiasingLevel )
{
	mSettings.antialiasingLevel = antialiasingLevel;
	mWindow.create( sf::VideoMode( windowSize.x, windowSize.y, 32 ), windowTitle, sf::Style::Default, mSettings );
	if( !mWindow.isOpen() )
	{
		throw std::runtime_error( "SFMLAdapter::openWindow: couldn't initialize window" );
		return;
	}
	mWindow.clear( sf::Color( 0, 0, 0 ) );
	mWindow.setVerticalSyncEnabled( vsync );
	mWindow.setFramerateLimit( fpsLimit );
}

bool SFMLAdapter::isRunning() const noexcept
{
	return mWindow.isOpen();
}

bool SFMLAdapter::isKeyPressed( sf::Keyboard::Key key ) const noexcept
{
	return mKeyboard.isKeyPressed( key );
}

std::vector< sf::Event > SFMLAdapter::getEvents() noexcept
{
	std::vector< sf::Event > output;
	while( mWindow.pollEvent( mEvent ) )
	{
		output.push_back( mEvent );
	}
	return output;
}

sf::RenderWindow& SFMLAdapter::getWindow() noexcept
{
	return mWindow;
}

sf::Transform& SFMLAdapter::getTransform() noexcept
{
	return mTransform;
}

Size SFMLAdapter::getWindowSize() const noexcept
{
	return mWindow.getSize();
}
