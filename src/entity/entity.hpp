#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
//
#include <typedef.hpp>
#include <data/loadable.hpp>

class EntitySubtype;

class Entity : public virtual Loadable, public virtual sf::Drawable, public sf::Transformable
{
public:
	Entity( const Dataset& dataset, const LPP::Table* table );
	Entity( const EntitySubtype* subtype );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

	virtual void simulate();

	const Vector& getVelocity() const noexcept;

	void addVelocity( const Vector& value ) noexcept;
private:
	Vector mVelocity;
	const EntitySubtype* mSubtype = nullptr;
};

#endif
