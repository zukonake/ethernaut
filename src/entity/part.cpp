#include "part.hpp"
//
#include <conversion.hpp>
#include <core/dataset.hpp>
#include <entity/partSubtype.hpp>

Part::Part( const Dataset& dataset, const LPP::Table* table ) :
	mTransform( conversion::tableToTransform( table->at< LPP::Table >( "transform" ))),
	mSubtype( dataset.getObject< PartSubtype >( *table->at< LPP::String >( "subtype" ))),
	mColor( conversion::tableToColor( table->at< LPP::Table >( "color" )))
{

}

void Part::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if( mSubtype != nullptr )
	{
		states.transform.combine( mTransform );
		target.draw( *mSubtype, states );
	}
}
