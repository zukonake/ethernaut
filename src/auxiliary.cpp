#include "auxiliary.hpp"

Point aux::tableToPoint( const LPP::Table* table )
{
	Point returnValue;
	returnValue.x = *table->at< LPP::Number >( 1 );
	returnValue.y = *table->at< LPP::Number >( 2 );
	return returnValue;
}

Size aux::tableToSize( const LPP::Table* table )
{
	Size returnValue;
	returnValue.x = *table->at< LPP::Number >( 1 );
	returnValue.y = *table->at< LPP::Number >( 2 );
	return returnValue;
}

sf::Color aux::tableToColor( const LPP::Table* table )
{
	sf::Color returnValue;
	returnValue.r = *table->at< LPP::Number >( 1 );
	returnValue.g = *table->at< LPP::Number >( 2 );
	returnValue.b = *table->at< LPP::Number >( 3 );
	returnValue.a = *table->at< LPP::Number >( 4 );
	return returnValue;
}

sf::Transform aux::tableToTransform( const LPP::Table* table )
{
	sf::Transform returnValue;
	returnValue.translate( tableToPoint( table->at< LPP::Table >( "position" )));
	returnValue.rotate( *table->at< LPP::Number >( "rotation" ));
	returnValue.scale( tableToPoint( table->at< LPP::Table >( "scale" )));
	return returnValue;
}

sf::Color aux::averageColors( const sf::Color& color1, const sf::Color& color2 )
{
	return sf::Color(( color1.r + color2.r ) / 2, ( color1.g + color2.g ) / 2, ( color1.b + color2.b ) / 2, ( color1.a + color2.a ) / 2 );
}

void aux::setTransformable( sf::Transformable& transformable, const LPP::Table* table )
{
	transformable.move( tableToPoint( table->at< LPP::Table >( "position" )));
	transformable.rotate( *table->at< LPP::Number >( "rotation" ));
	transformable.scale( tableToPoint( table->at< LPP::Table >( "scale" )));
}
