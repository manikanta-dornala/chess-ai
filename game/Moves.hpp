#pragma once
#include <iostream>
#include <list>
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
using namespace std;

namespace Moves
{
	vector<Move> GetPieceMoves(Position position, Square board[8][8]);
	vector<Move> GetPawnMovesForSquare(Position position, Square board[8][8]);
	vector<Move> GetMovesForSquare(Position position, Square board[8][8]);
	vector<Move> GetRegularMoves(Color turn, Square board[8][8]);
	vector<Move> GetEnpassantCaptures(Position enapassant_target, Square board[8][8]);
	vector<Move> GetLegalMoves(Color turn, CastlingRights castling_rights, Position enpassant_target, Square board[8][8]);
} // namespace Moves