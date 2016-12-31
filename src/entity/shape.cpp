#include "shape.hpp"
//
#include <cmath>
//
#include <conversion.hpp>

Shape::Shape( const Vectors& points, const Vectors& customJoints ) :
	sf::ConvexShape( points.size())
{
	initializeConvexShape( points, customJoints );
}

Shape::Shape( const Dataset& dataset, const LPP::Table* table ) :
	Loadable( dataset, table )
{
	const LPP::Table* pointsTable = table->at< LPP::Table >( "points" );
	const LPP::Table* customJointsTable = table->at< LPP::Table >( "customJoints" );
	Vectors points;
	Vectors customJoints;
	for( Index iterator = 1; iterator <= pointsTable->get().first.size(); iterator++ )
	{
		points.push_back( conversion::tableToPoint( pointsTable->at< LPP::Table >( iterator )));
	}
	if( customJointsTable->get().first.size() != 0 )
	{
		for( Index iterator = 1; iterator <= pointsTable->get().first.size(); iterator++ )
		{
			customJoints.push_back( conversion::tableToPoint( pointsTable->at< LPP::Table >( iterator )));
		}
	}
	if( table->get().second.count( "origin" ) != 0 )
	{
		sf::ConvexShape::setOrigin( conversion::tableToPoint( table->at< LPP::Table >( "origin" )));
	}
	initializeConvexShape( points, customJoints );
}

const Vectors& Shape::getJoints() const noexcept
{
	return mJoints;
}

void Shape::initializeConvexShape( const Vectors& points, const Vectors& customJoints )
{
	sf::ConvexShape::setPointCount( points.size());
	for( Index iterator = 0; iterator < points.size(); iterator++ )
	{
		sf::ConvexShape::setPoint( iterator, points[ iterator ]);
		Point point1;
		Point point2;
		if( iterator == 0 )
		{
			point1 = points[ points.size() - 1 ];
		}
		else
		{
			point1 = points[ iterator - 1];
		}
			point2 = points[ iterator ];
			mJoints.push_back( Point( point1.x + ( std::abs( point1.x - point2.x ) / 2 ), point1.y + ( std::abs( point1.y - point2.y ) / 2 )));
	}
	for( auto& iterator : customJoints )
	{
		mJoints.push_back( iterator );
	}
}
