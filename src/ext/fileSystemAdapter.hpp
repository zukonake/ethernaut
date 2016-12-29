#ifndef FILESYSTEMADAPTER_HPP
#define FILESYSTEMADAPTER_HPP

#include <fstream>
#include <string>
#include <vector>
//
#include <nonCopyable.hpp>

class FileSystemAdapter : std::fstream, virtual NonCopyable
{
public:
	FileSystemAdapter() = default;

	~FileSystemAdapter();

	std::vector< std::string > listFiles( const std::string& directoryPath, const std::string& targetExtension = ".lua" );
};

#endif
