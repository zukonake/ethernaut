#ifndef OUTPUTDATA_HPP
#define OUTPUTDATA_HPP

#include <vector>
#include <string>
//
#include <typedef.hpp>
#include <entity/part.hpp>

struct OutputData
{
	std::vector< Part > entities; //TODO
	Size windowSize;
	std::string windowTitle;
	bool end = false;
};

#endif
