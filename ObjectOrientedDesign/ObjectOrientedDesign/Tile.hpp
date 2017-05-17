#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include "Character.hpp"

enum tileData { Nothing, Wall, Ladder, Hostile, Trap1, Trap2 };

struct tile
{
	position position;
	tileData tileData;
	Character* occupant;
};

#endif