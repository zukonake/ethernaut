#include "part.hpp"
//
#include <auxiliary.hpp>
#include <data/dataset.hpp>
#include <entity/partSubtype.hpp>

Part::Part( const Dataset& dataset, const LPP::Table* table ) :
	mSubtype( dataset.getObject< PartSubtype >( *table->at< LPP::String >( "subtype" ))),
	mColor( aux::tableToColor( table->at< LPP::Table >( "color" )))
{
	aux::setTransformable( *this, table->at< LPP::Table >( "transform" ));
}

void Part::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if( mSubtype != nullptr )
	{
		states.transform.combine( this->getTransform());
		mSubtype->draw( target, states, mColor );
	}
}
