#ifndef PART_HPP
#define PART_HPP

#include <luaPP.hpp>
//
#include <ext/loadable.hpp>
#include <entity/jointShape.hpp>

class Part : public Loadable
{
public:
	Part( const JointShape& shape );
	Part( const LPP::Table* table );
private:
	const JointShape& mShape;
};

#endif
