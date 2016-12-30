#include "part.hpp"
//
#include <core/dataset.hpp>

Part::Part( const Dataset& dataset, const LPP::Table* table ) :
	Loadable( dataset, table ),
	mShape( *dataset.getObject< Shape >( *table->at< LPP::String >( "shape" )))
{

}

void Part::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	states.transform.combine( mTransform );
	target.draw( mShape, states );
}
