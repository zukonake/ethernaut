#include "shape.hpp"
//
#include <cmath>
//
#include <auxiliary.hpp>

Shape::Shape( const std::vector< Point >& points, const std::vector< Point >& customJoints ) :
	sf::ConvexShape( points.size())
{
	//initializeConvexShape( points, customJoints );TODO
}

Shape::Shape( const Dataset& dataset, const LPP::Table* table ) :
	Loadable( dataset, table )
{
	const LPP::Table* pointsTable = table->at< LPP::Table >( "points" );
	const LPP::Table* customJointsTable = table->at< LPP::Table >( "customJoints" );
	std::vector< Point > points;
	std::vector< Point > customJoints;
	for( Index iterator = 1; iterator <= pointsTable->get().first.size(); iterator++ )
	{
		points.push_back( aux::tableToPoint( pointsTable->at< LPP::Table >( iterator )));
	}
	if( customJointsTable->get().first.size() != 0 )
	{
		for( Index iterator = 1; iterator <= pointsTable->get().first.size(); iterator++ )
		{
			customJoints.push_back( aux::tableToPoint( pointsTable->at< LPP::Table >( iterator )));
		}
	}
	initializeConvexShape( points, customJoints, aux::tableToPoint( table->at< LPP::Table >( "origin" )));
}

void Shape::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( static_cast< sf::ConvexShape >( *this ), states );
	states.transform.combine( sf::ConvexShape::getTransform());
	for( auto& iJoint : mJoints )
	{
		sf::CircleShape jointSquare( 2, 4 );
		jointSquare.setOrigin( 2, 2 );
		jointSquare.setPosition( iJoint );
		jointSquare.setFillColor( sf::Color::Red );
		target.draw( jointSquare, states );
	}
}

const std::vector< Point >& Shape::getJoints() const noexcept
{
	return mJoints;
}

void Shape::initializeConvexShape( const std::vector< Point >& points, const std::vector< Point >& customJoints, const Point& origin )
{
	sf::ConvexShape::setPointCount( points.size());
	for( Index iterator = 0; iterator < points.size(); iterator++ )
	{
		sf::ConvexShape::setPoint( iterator, points[ iterator ]);
	}
	for( Index iterator = 0; iterator < points.size(); iterator++ )
	{
		Point point1;
		Point point2;
		Point finalPoint( 0, 0 );
		Point distance( 0, 0 );
		if( iterator == 0 )
		{
			point1 = points[ points.size() - 1 ];
		}
		else
		{
			point1 = points[ iterator - 1];
		}
			point2 = points[ iterator ];
			distance = { ( std::abs( point1.x - point2.x ) / 2 ), ( std::abs( point1.y - point2.y ) / 2 ) };
			if( point1.x <= point2.x )
			{
				finalPoint.x = point1.x + distance.x;
			}
			else
			{
				finalPoint.x += point1.x - distance.x;
			}
			if( point1.y <= point2.y )
			{
				finalPoint.y = point1.y + distance.y;
			}
			else
			{
				finalPoint.y += point1.y - distance.y;
			}
			mJoints.push_back( finalPoint );
	}
	for( auto& iJoint : customJoints )
	{
		mJoints.push_back( iJoint);
	}
	sf::ConvexShape::setOrigin( origin );
	sf::ConvexShape::setOutlineThickness( 1 );
}
