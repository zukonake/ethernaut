#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
//
#include <typedef.hpp>
#include <ext/loadable.hpp>

class EntitySubtype;

class Entity : public virtual Loadable, public virtual sf::Drawable
{
public:
	Entity( const Dataset& dataset, const LPP::Table* table );
	Entity( const EntitySubtype* subtype );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

	sf::Transform mTransform;
private:
	const EntitySubtype* mSubtype = nullptr;
};

#endif
