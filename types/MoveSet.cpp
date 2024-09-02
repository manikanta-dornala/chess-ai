#pragma once
#include "../utils/utils.hpp"
#include "../structs/structs.hpp"
#include "../enums/enums.hpp"

#include <iostream>
using namespace std;

// Define vectors of MoveSet for each piece type
const vector<SquarePosition> rook_moveset = {
	{ .rank = 0, .file = 1 },
	{ .rank = 0, .file = -1 },
	{ .rank = 1, .file = 0 },
	{ .rank = -1, .file = 0 }
};
const vector<SquarePosition> bishop_moveset = {
	{ .rank = 1, .file = 1 },
	{ .rank = 1, .file = -1 },
	{ .rank = -1, .file = 1 },
	{ .rank = -1, .file = -1 }
};
const vector<SquarePosition> knight_moveset = {
	{ .rank = 2, .file = 1 },
	{ .rank = 2, .file = -1 },
	{ .rank = -2, .file = 1 },
	{ .rank = -2, .file = -1 },
	{ .rank = 1, .file = 2 },
	{ .rank = 1, .file = -2 },
	{ .rank = -1, .file = 2 },
	{ .rank = -1, .file = -2 }
};
const vector<SquarePosition> queen_moveset = Concatenate(rook_moveset, bishop_moveset);
const vector<SquarePosition> nil_moveset = vector<SquarePosition>();

const vector<SquarePosition>& GetPieceMoveSets(PieceType type)
{
	switch (type)
	{
		case PIECETYPE_ROOK:
			return rook_moveset;
		case PIECETYPE_BISHOP:
			return bishop_moveset;
		case PIECETYPE_KNIGHT:
			return knight_moveset;
		case PIECETYPE_QUEEN:
			return queen_moveset;
		case PIECETYPE_KING:
			return queen_moveset;
		default:
			return nil_moveset;
	}
}