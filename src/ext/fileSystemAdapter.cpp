#include "fileSystemAdapter.hpp"
#include <exception>
//
#include <boost/filesystem.hpp>

FileSystemAdapter::~FileSystemAdapter()
{
	close();
}

std::vector< std::string > FileSystemAdapter::listFiles( const std::string& directoryPath, const std::string& targetExtension )
{
	std::vector< std::string > output;
	if( boost::filesystem::is_directory( directoryPath ))
	{
		boost::filesystem::directory_iterator endIterator;
		for( boost::filesystem::directory_iterator iFile( directoryPath );
			iFile != endIterator;
			++iFile )
		{
			if( !boost::filesystem::is_directory( iFile->status() ) and iFile->path().extension() == targetExtension )
			{
				output.push_back( iFile->path().string() );
			}
		}
	}
	else
	{
		throw std::runtime_error( "FileSystemAdapter::getFilesInDirectory, Couldn't open directory: " + directoryPath + "." );
		return std::vector< std::string >();
	}
	return output;
}
