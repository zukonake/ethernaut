#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <SFML/Graphics.hpp>
//
#include <luaPP.hpp>
//
#include <typedef.hpp>

namespace conversion
{
	Point tableToPoint( const LPP::Table* table );
	Size tableToSize( const LPP::Table* table );
	sf::Color tableToColor( const LPP::Table* table );
	sf::Transform tableToTransform( const LPP::Table* table );
}

#endif
