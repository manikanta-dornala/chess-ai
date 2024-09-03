

#include <iostream>
#include <string>
#include <map>
#include "../enums/enums.hpp"
#include "../utils/utils.hpp"
#include "structs.hpp"
using namespace std;

string Position::GetSquareCode() const
{
	char result[2];
	result[0] = 'a' + this->file;
	result[1] = '1' + this->rank;
	return string(result);
}

bool Position::IsValidPosition() const
{
	return this->rank >= 0 && this->rank <= 7 && this->file >= 0 && this->rank <= 7;
}
// Define vectors of MoveSet for each piece type
const vector<Position> rook_moveset = {
	{ .rank = 0, .file = 1 },
	{ .rank = 0, .file = -1 },
	{ .rank = 1, .file = 0 },
	{ .rank = -1, .file = 0 }
};
const vector<Position> bishop_moveset = {
	{ .rank = 1, .file = 1 },
	{ .rank = 1, .file = -1 },
	{ .rank = -1, .file = 1 },
	{ .rank = -1, .file = -1 }
};
const vector<Position> knight_moveset = {
	{ .rank = 2, .file = 1 },
	{ .rank = 2, .file = -1 },
	{ .rank = -2, .file = 1 },
	{ .rank = -2, .file = -1 },
	{ .rank = 1, .file = 2 },
	{ .rank = 1, .file = -2 },
	{ .rank = -1, .file = 2 },
	{ .rank = -1, .file = -2 }
};
const vector<Position>	queen_moveset = Concatenate(rook_moveset, bishop_moveset);
const vector<Position>	nil_moveset = vector<Position>();
const vector<Position>& GetPieceMoveSet(PieceType piece_type)
{

	switch (piece_type)
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
	};
}
