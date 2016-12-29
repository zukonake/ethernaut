#include "jointShape.hpp"
//
#include <cstddef>
#include <cmath>

JointShape::JointShape( const Vectors& points, const Vectors& customJoints ) :
	ConvexShape( points.size())
{
	for( std::size_t iterator = 0; iterator < points.size(); iterator++ )
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

const Vectors& JointShape::getJoints() const noexcept
{
	return mJoints;
}
