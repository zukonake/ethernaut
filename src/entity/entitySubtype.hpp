#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <vector>
//
#include <SFML/Graphics.hpp>
//
#include <data/loadable.hpp>
#include <entity/part.hpp>

class EntitySubtype : public virtual Loadable, public virtual sf::Drawable
{
public:
	EntitySubtype( const Dataset& dataset, const LPP::Table* table );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	std::vector< Part > mParts;
};

#endif
