#pragma once
#include "../enums/enums.hpp"
#include "Piece.hpp"

struct Square
{
	Piece piece;
};

struct SquarePosition
{
	int rank;
	int file;
};
