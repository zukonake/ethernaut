#ifndef SFMLADAPTER_HPP
#define SFMLADAPTER_HPP

#include <cstdint>
#include <string>
//
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//
#include <nonCopyable.hpp>
//
#include <typedef.hpp>

class SFMLAdapter : virtual NonCopyable
{
public:
	SFMLAdapter() = default;

	virtual ~SFMLAdapter() noexcept;

	void update() noexcept;
	void draw( const sf::Drawable& drawable, sf::RenderStates states = sf::RenderStates::Default );

	void openWindow( const Size& windowSize, const std::string& windowTitle, uint8_t fpsLimit = 0, bool vsync = false, uint8_t antialiasingLevel = 0 );

	bool isRunning() const noexcept;
	bool isKeyPressed( sf::Keyboard::Key key ) const noexcept;

	std::vector< sf::Event > getEvents() noexcept;
	sf::RenderWindow& getWindow() noexcept;
	sf::Transform& getTransform() noexcept;
	Size getWindowSize() const noexcept;
private:
	sf::ContextSettings mSettings;
	sf::Transform mTransform;
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::Keyboard mKeyboard;
};

#endif
