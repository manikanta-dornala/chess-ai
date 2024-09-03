#pragma once
#include <iostream>
#include <list>
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
using namespace std;

namespace Moves
{
	vector<Move> GetPieceMoves(const Position& position, const Square (&board)[8][8]);
	vector<Move> GetPawnMovesForSquare(const Position& position, const Square (&board)[8][8]);
	vector<Move> GetMovesForSquare(const Position& position, const Square (&board)[8][8]);
	vector<Move> GetRegularMoves(const Color& turn, const Square (&board)[8][8]);
	vector<Move> GetEnpassantCaptures(const Position& enapassant_target, const Square (&board)[8][8]);
	vector<Move> GetLegalMoves(const Color& turn, const CastlingRights& castling_rights, const Position& enpassant_target, const Square (&board)[8][8]);
} // namespace Moves