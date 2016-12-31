#include "entity.hpp"
//
#include <conversion.hpp>
#include <entity/entitySubtype.hpp>
#include <core/dataset.hpp>

Entity::Entity( const Dataset& dataset, const LPP::Table* table ) :
	mTransform( conversion::tableToTransform( table->at< LPP::Table >( "transform" ))),
	mSubtype( dataset.getObject< EntitySubtype >( *table->at< LPP::String >( "subtype" )))
{

}

Entity::Entity( const EntitySubtype* subtype ) :
	mSubtype( subtype )
{

}

void Entity::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if( mSubtype != nullptr )
	{
		states.transform.combine( mTransform );
		target.draw( *mSubtype, states );
	}
}
