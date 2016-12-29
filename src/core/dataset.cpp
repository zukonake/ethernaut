#include "dataset.hpp"
//
#include <entity/jointShape.hpp>
#include <entity/part.hpp>

Dataset::Dataset()
{
	loadConfig();
	std::string datasetName = *getConfig< LPP::String >( "datasetName" );
	initializeObjects< JointShape >( mDatasetPath + datasetName + "shapes" );
	initializeObjects< Part >( mDatasetPath + datasetName + "parts" );
}

Dataset::~Dataset()
{
	for( auto iPair : mObjects )
	{
		delete iPair.second;
	}
	delete mConfig;
	delete mConfigFile;
}

const sf::Texture& Dataset::getTileset() const noexcept
{
	return mTileset;
}

void Dataset::loadConfig()
{
	mConfigFile = mLuaStack.loadFile( mDatasetPath + mConfigPath );
	mLuaStack.call();
	mLuaStack.loadGlobal( "config" );
	mConfig = mLuaStack.get< LPP::Table >();
	mTileset.loadFromFile( *getConfig< LPP::String >( "texturePath" ));
}
