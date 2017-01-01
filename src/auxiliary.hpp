#ifndef AUXILIARY_HPP
#define AUXILIARY_HPP

#include <SFML/Graphics.hpp>
//
#include <luaPP.hpp>
//
#include <typedef.hpp>

namespace aux
{
	Point tableToPoint( const LPP::Table* table );
	Size tableToSize( const LPP::Table* table );
	sf::Color tableToColor( const LPP::Table* table );
	sf::Transform tableToTransform( const LPP::Table* table );
	sf::Color averageColors( const sf::Color& color1, const sf::Color& color2 );
	void setTransformable( sf::Transformable& transformable, const LPP::Table* table );
}

#endif
