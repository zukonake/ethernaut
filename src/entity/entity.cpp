#include "entity.hpp"
//
#include <auxiliary.hpp>
#include <entity/entitySubtype.hpp>
#include <data/dataset.hpp>

Entity::Entity( const Dataset& dataset, const LPP::Table* table ) :
	mSubtype( dataset.getObject< EntitySubtype >( *table->at< LPP::String >( "subtype" )))
{
	aux::setTransformable( *this, table->at< LPP::Table >( "transform" ));
}

Entity::Entity( const EntitySubtype* subtype ) :
	mSubtype( subtype )
{

}

void Entity::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if( mSubtype != nullptr )
	{
		states.transform.combine( this->getTransform());
		target.draw( *mSubtype, states );
	}
}

void Entity::simulate()
{
	sf::Transformable::move( mVelocity );
}

const Vector& Entity::getVelocity() const noexcept
{
	return mVelocity;
}

void Entity::addVelocity( const Vector& value ) noexcept
{
	sf::Transform rotation;
	rotation.rotate( sf::Transformable::getRotation());
	mVelocity += rotation * value;
}
