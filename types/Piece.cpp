#pragma once
#include "Color.cpp"
#include <map>
using namespace std;

enum PieceType
{
	PIECETYPE_NIL = 0,
	PIECETYPE_PAWN,
	PIECETYPE_KNIGHT,
	PIECETYPE_BISHOP,
	PIECETYPE_ROOK,
	PIECETYPE_QUEEN,
	PIECETYPE_KING
};

const map<char, PieceType> PieceTypeMap = {
	{ 'p', PIECETYPE_PAWN },
	{ 'n', PIECETYPE_KNIGHT },
	{ 'b', PIECETYPE_BISHOP },
	{ 'r', PIECETYPE_ROOK },
	{ 'q', PIECETYPE_QUEEN },
	{ 'k', PIECETYPE_KING }
};

struct Piece
{
	PieceType type;
	Color	  color;
};

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

const Piece DefaultPiece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };
