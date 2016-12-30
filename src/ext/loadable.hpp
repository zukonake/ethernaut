#ifndef LOADABLE_HPP
#define LOADABLE_HPP

namespace LPP
{
	class Table;
}

class Dataset;

class Loadable
{
public:
	Loadable() = default;
	explicit Loadable( const Dataset& dataset, const LPP::Table* table = nullptr ) { }

	virtual ~Loadable() = default;
};

#endif
