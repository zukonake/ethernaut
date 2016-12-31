#include "partSubtype.hpp"
//
#include <entity/shape.hpp>
#include <core/dataset.hpp>
#include <conversion.hpp>

PartSubtype::PartSubtype( const Dataset& dataset, const LPP::Table* table ) :
	Loadable( dataset, table ),
	mShape( dataset.getObject< Shape >( *table->at< LPP::String >( "shape" ))),
	mColor( conversion::tableToColor( table->at< LPP::Table >( "color" )))
{

}

void PartSubtype::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if( mShape != nullptr )
	{
		Shape renderShape = *mShape;
		renderShape.setFillColor( mColor );
		target.draw( renderShape, states );
	}
}
