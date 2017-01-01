#ifndef PARTSUBTYPE_HPP
#define PARTSUBTYPE_HPP

#include <SFML/Graphics.hpp>
//
#include <luaPP.hpp>
//
#include <data/loadable.hpp>

class Shape;
class Dataset;

class PartSubtype : public virtual Loadable, public virtual sf::Drawable
{
	friend class Part;
public:
	PartSubtype( const Dataset& dataset, const LPP::Table* table = nullptr );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states, const sf::Color& color ) const;
private:
	const Shape* mShape = nullptr;
	sf::Color mColor;
};

#endif
