#include "shape.hpp"
//
#include <cmath>
//
#include <conversion.hpp>

Shape::Shape( const Vectors& points, const Vectors& customJoints ) :
	ConvexShape( points.size())
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
	for( Index iterator = 0; iterator != pointsTable->get().size(); iterator++ )
	{
		points.push_back( conversion::tableToPoint( pointsTable->at< LPP::Table >( "p" + std::to_string( iterator ))));
	}
	if( customJointsTable->get().size() != 0 )
	{
		for( Index iterator = 0; iterator != pointsTable->get().size(); iterator++ )
		{
			customJoints.push_back( conversion::tableToPoint( pointsTable->at< LPP::Table >( "p" + std::to_string( iterator ))));
		}
	}
	initializeConvexShape( points, customJoints );
}

const Vectors& Shape::getJoints() const noexcept
{
	return mJoints;
}

void Shape::initializeConvexShape( const Vectors& points, const Vectors& customJoints )
{
	ConvexShape::setPointCount( points.size());
	for( Index iterator = 0; iterator < points.size(); iterator++ )
	{
		ConvexShape::setPoint( iterator, points[ iterator ]);
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
