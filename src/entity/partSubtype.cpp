#include "partSubtype.hpp"
//
#include <entity/shape.hpp>
#include <data/dataset.hpp>
#include <auxiliary.hpp>

PartSubtype::PartSubtype( const Dataset& dataset, const LPP::Table* table ) :
	Loadable( dataset, table ),
	mShape( dataset.getObject< Shape >( *table->at< LPP::String >( "shape" ))),
	mColor( aux::tableToColor( table->at< LPP::Table >( "color" )))
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

void PartSubtype::draw( sf::RenderTarget& target, sf::RenderStates states, const sf::Color& color ) const
{
	if( mShape != nullptr )
	{
		Shape renderShape = *mShape;
		renderShape.setFillColor( aux::averageColors( mColor, color ));
		target.draw( renderShape, states );
	}
}
