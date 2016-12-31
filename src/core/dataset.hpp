#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include <unordered_map>
#include <iostream>
#include <stdexcept>
//
#include <SFML/Graphics/Texture.hpp>
//
#include <luaPP.hpp>
//
#include <ext/fileSystemAdapter.hpp>
#include <ext/loadable.hpp>
#include <entity/shape.hpp>
#include <entity/partSubtype.hpp>
#include <entity/entitySubtype.hpp>

class Loadable;

class Dataset
{
	const std::string mDatasetPath = "dataset/";
	const std::string mConfigPath = "config.lua";
public:
	Dataset();
	~Dataset();

	template < typename T = Loadable >
	const T* getObject( const std::string& key ) const;
	template < typename T = LPP::StackElement >
	const T* getConfig( const std::string& key ) const;
private:
	template< typename T = Loadable >
	void initializeObjects( const std::string& directoryPath );
	void loadConfig();

	FileSystemAdapter mFileSystem;
	LPP::LuaStack mLuaStack;

	std::unordered_map< std::string, const Loadable* > mObjects;

	const LPP::Table* mConfig = nullptr;
	const LPP::Function* mConfigFile = nullptr;
};

template < typename T >
const T* Dataset::getObject( const std::string& key ) const
{
	return dynamic_cast< const T* >( mObjects.at( key ));
}

template < typename T >
const T* Dataset::getConfig( const std::string& key ) const
{
	return mConfig->at< T >( key );
}

template< typename T >
void Dataset::initializeObjects( const std::string& directoryPath )
{
	std::unordered_map< std::string, Loadable* > output;
	try
	{
		for( auto iFile : mFileSystem.listFiles( directoryPath ) )
		{
			const LPP::Function* script = mLuaStack.loadFile( iFile );
			mLuaStack.call();
			mLuaStack.loadGlobals();
			output[ *mLuaStack.at< LPP::String >( "loadableName" ) ] = new T( *this, mLuaStack.getGlobals());
			std::cout << "Dataset::initializeObjects()::Loaded: " << mLuaStack.at< LPP::String >( "loadableName" )->get() << "\n";
			delete script;
		}
	}
	catch( std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	mObjects.insert( output.begin(), output.end());
}

#endif
