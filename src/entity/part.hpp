#ifndef PART_HPP
#define PART_HPP

#include <luaPP.hpp>
//
#include <ext/loadable.hpp>
#include <entity/shape.hpp>

class Dataset;

class Part : public virtual Loadable, public sf::Drawable
{
public:
	Part( const Dataset& dataset, const LPP::Table* table = nullptr );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
private:
	const Shape& mShape;
	sf::Transform mTransform;
};

#endif
