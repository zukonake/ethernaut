#ifndef LOADABLE_HPP
#define LOADABLE_HPP

namespace LPP
{
	class Table;
}

class Loadable
{
public:
	Loadable() = default;
	explicit Loadable( const LPP::Table* table ) { }

	virtual ~Loadable() = default;
};

#endif
