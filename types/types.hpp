#pragma once
#include <iostream>
#include <map>
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
using namespace std;

const vector<SquarePosition>& GetPieceMoveSets(PieceType type);
string						  GetSquareCode(SquarePosition position);
bool						  IsValidPosition(SquarePosition position);
char						  GetPieceCode(Piece piece);

const map<char, PieceType> PieceTypeMap = {
	{ 'p', PIECETYPE_PAWN },
	{ 'n', PIECETYPE_KNIGHT },
	{ 'b', PIECETYPE_BISHOP },
	{ 'r', PIECETYPE_ROOK },
	{ 'q', PIECETYPE_QUEEN },
	{ 'k', PIECETYPE_KING }
};
const Piece DefaultPiece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };