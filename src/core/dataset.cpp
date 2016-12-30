#include "dataset.hpp"
//
#include <entity/shape.hpp>
#include <entity/part.hpp>

Dataset::Dataset()
{
	loadConfig();
	std::string datasetName = *getConfig< LPP::String >( "datasetName" );
	initializeObjects< Shape >( mDatasetPath + datasetName + "shape" );
	initializeObjects< Part >( mDatasetPath + datasetName + "part" );
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

void Dataset::loadConfig()
{
	mConfigFile = mLuaStack.loadFile( mDatasetPath + mConfigPath );
	mLuaStack.call();
	mLuaStack.loadGlobal( "config" );
	mConfig = mLuaStack.get< LPP::Table >();
}
