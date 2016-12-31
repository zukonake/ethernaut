#ifndef OUTPUTDATA_HPP
#define OUTPUTDATA_HPP

#include <vector>
#include <string>
//
#include <typedef.hpp>
#include <entity/entity.hpp>

struct OutputData
{
	std::vector< Entity > entities;
	bool end = false;
};

#endif
