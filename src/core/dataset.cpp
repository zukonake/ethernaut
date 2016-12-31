#include "dataset.hpp"

Dataset::Dataset()
{
	loadConfig();
	std::string datasetName = getConfig< LPP::String >( "datasetName" )->get() + "/";
	initializeObjects< Shape >( mDatasetPath + datasetName + "shape" );
	initializeObjects< PartSubtype >( mDatasetPath + datasetName + "partSubtype" );
	initializeObjects< EntitySubtype >( mDatasetPath + datasetName + "entitySubtype" );
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
