#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics.hpp>
//
#include <luaPP.hpp>
//
#include <data/loadable.hpp>
#include <typedef.hpp>

class Shape : public virtual Loadable, public sf::ConvexShape
{
public:
	Shape( const std::vector< Point >& points, const std::vector< Point >& customJoints );
	Shape( const Dataset& dataset, const LPP::Table* table );

	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

	const std::vector< Point >& getJoints()  const noexcept;
private:
	void initializeConvexShape( const std::vector< Point >& points, const std::vector< Point >& customJoints, const Point& origin );

	std::vector< Point > mJoints;
};

#endif
