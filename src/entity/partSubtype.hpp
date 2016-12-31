#ifndef PARTSUBTYPE_HPP
#define PARTSUBTYPE_HPP

#include <SFML/Graphics.hpp>
//
#include <luaPP.hpp>
//
#include <ext/loadable.hpp>

class Shape;
class Dataset;

class PartSubtype : public virtual Loadable, public virtual sf::Drawable
{
public:
	PartSubtype( const Dataset& dataset, const LPP::Table* table = nullptr );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	const Shape* mShape = nullptr;
	sf::Color mColor;
};

#endif
