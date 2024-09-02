#pragma once
#include <list>
#include <map>
#include <string>
#include <vector>
#include "../utils/vector.cpp"
#include "Piece.cpp"
#include "Square.cpp"
using namespace std;

enum MoveType
{
	MOVETYPE_NIL = 0,
	MOVETYPE_MOVE,
	MOVETYPE_DOUBLE_MOVE,
	MOVETYPE_CAPTURE,
	MOVETYPE_ENPASSANT,
	MOVETYPE_PROMOTE,
	MOVETYPE_CASTLING
};

struct Move
{
	SquarePosition curr;
	SquarePosition target;
	MoveType	   type;
};
