#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <luaPP.hpp>
//
#include <typedef.hpp>

namespace conversion
{
	Point tableToPoint( const LPP::Table* table );
	Size tableToSize( const LPP::Table* table );
}

#endif
