#pragma once
#include "../structs/structs.hpp"
#include "../enums/enums.hpp"
#include <map>
using namespace std;

char GetPieceCode(Piece piece)
{
	char code = ' ';
	switch (piece.type)
	{
		case PIECETYPE_PAWN:
			code = 'p';
			break;
		case PIECETYPE_KNIGHT:
			code = 'n';
			break;
		case PIECETYPE_BISHOP:
			code = 'b';
			break;
		case PIECETYPE_ROOK:
			code = 'r';
			break;
		case PIECETYPE_QUEEN:
			code = 'q';
			break;
		case PIECETYPE_KING:
			code = 'k';
			break;
		default:
			code = '.';
			break;
	}
	return piece.color == COLOR_WHITE ? toupper(code) : tolower(code);
}
