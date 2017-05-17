#ifndef CHARACTERDATA_HPP
#define CHARACTERDATA_HPP


#include "Character.hpp"	// Position + Direction

struct characterData
{
	int* Health = nullptr;
	position* Position = nullptr;
	direction*  Direction = nullptr;
};

#endif