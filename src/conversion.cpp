#include "conversion.hpp"

Point conversion::tableToPoint( const LPP::Table* table )
{
	Point returnValue;
	returnValue.x = *table->at< LPP::Number >( "x" );
	returnValue.y = *table->at< LPP::Number >( "y" );
	return returnValue;
}

Size conversion::tableToSize( const LPP::Table* table )
{
	Size returnValue;
	returnValue.x = *table->at< LPP::Number >( "x" );
	returnValue.y = *table->at< LPP::Number >( "y" );
	return returnValue;
}
