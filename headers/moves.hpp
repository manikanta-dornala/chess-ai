#pragma once
#include <iostream>
#include <list>
#include "enums.hpp"
#include "structs.hpp"
using namespace std;

namespace Moves
{
    vector<Move> GetPieceMoves(const Position& position, const Piece (&board)[8][8]);
    vector<Move> GetPawnMovesForPiece(const Position& position, const Piece (&board)[8][8]);
    vector<Move> GetMovesForPiece(const Position& position, const Piece (&board)[8][8]);
    vector<Move> GetRegularMoves(const Color& turn, const Piece (&board)[8][8]);
    vector<Move> GetEnpassantCaptures(const Position& enapassant_target, const Piece (&board)[8][8]);
    vector<Move> GetLegalMoves(const Color& turn, const CastlingRights& castling_rights, const Position& enpassant_target, const Piece (&board)[8][8]);
} // namespace Moves