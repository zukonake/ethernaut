#ifndef JOINTSHAPE_HPP
#define JOINTSHAPE_HPP

#include <SFML/Graphics.hpp>
//
#include <luaPP.hpp>
//
#include <ext/loadable.hpp>
#include <typedef.hpp>

class JointShape : public sf::ConvexShape, public Loadable
{
public:
	JointShape( const Vectors& points, const Vectors& customJoints = Vectors());
	JointShape( const LPP::Table* table );
	const Vectors& getJoints()  const noexcept;
private:
	Vectors mJoints;
};

#endif
