#pragma once
#include "Square.hpp"
#include "../enums/enums.hpp"

struct Move
{
	SquarePosition curr;
	SquarePosition target;
	MoveType	   type;
};
