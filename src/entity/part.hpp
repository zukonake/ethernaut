#ifndef PART_HPP
#define PART_HPP

#include <SFML/Graphics.hpp>
//
#include <typedef.hpp>
#include <data/loadable.hpp>

class PartSubtype;
class Dataset;

class Part : public virtual Loadable, public virtual sf::Drawable, public sf::Transformable
{
public:
	Part( const Dataset& dataset, const LPP::Table* table );
	Part( const PartSubtype* subtype, const sf::Color& color = sf::Color::White );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	const PartSubtype* mSubtype;
	sf::Color mColor;
};

#endif
