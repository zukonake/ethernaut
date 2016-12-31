#include "conversion.hpp"

Point conversion::tableToPoint( const LPP::Table* table )
{
	Point returnValue;
	returnValue.x = *table->at< LPP::Number >( 1 );
	returnValue.y = *table->at< LPP::Number >( 2 );
	return returnValue;
}

Size conversion::tableToSize( const LPP::Table* table )
{
	Size returnValue;
	returnValue.x = *table->at< LPP::Number >( 1 );
	returnValue.y = *table->at< LPP::Number >( 2 );
	return returnValue;
}

sf::Color conversion::tableToColor( const LPP::Table* table )
{
	sf::Color returnValue;
	returnValue.r = *table->at< LPP::Number >( 1 );
	returnValue.g = *table->at< LPP::Number >( 2 );
	returnValue.b = *table->at< LPP::Number >( 3 );
	returnValue.a = *table->at< LPP::Number >( 4 );
	return returnValue;
}

sf::Transform conversion::tableToTransform( const LPP::Table* table )
{
	sf::Transform returnValue;
	returnValue.translate( tableToPoint( table->at< LPP::Table >( "position" )));
	returnValue.rotate( *table->at< LPP::Number >( "rotation" ));
	returnValue.scale( tableToPoint( table->at< LPP::Table >( "scale" )));
	return returnValue;
}
