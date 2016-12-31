#include "entitySubtype.hpp"
//
#include <conversion.hpp>

EntitySubtype::EntitySubtype( const Dataset& dataset, const LPP::Table* table )
{
	const LPP::Table* partsTable = table->at< LPP::Table >( "parts" );
	for( Index iterator = 1; iterator <= partsTable->get().first.size(); iterator++ )
	{
		mParts.emplace_back( dataset, partsTable->at< LPP::Table >( iterator ));
	}
}

void EntitySubtype::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	for( auto& iPart : mParts )
	{
		target.draw( iPart, states );
	}
}
