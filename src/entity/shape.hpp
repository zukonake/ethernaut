#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics.hpp>
//
#include <luaPP.hpp>
//
#include <ext/loadable.hpp>
#include <typedef.hpp>

class Shape : public virtual Loadable, public sf::ConvexShape
{
public:
	Shape( const Vectors& points, const Vectors& customJoints = Vectors());
	Shape( const Dataset& dataset, const LPP::Table* table );
	
	const Vectors& getJoints()  const noexcept;
private:
	void initializeConvexShape( const Vectors& points, const Vectors& customJoints );

	Vectors mJoints;
};

#endif
