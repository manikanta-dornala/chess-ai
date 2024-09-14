#pragma once
#include <iostream>
#include <list>

#include "enums.hpp"
#include "structs.hpp"
using namespace std;

namespace Board {

Moves GetMovesForPieceAt(const Position position, const BoardPieces& board);
Moves GetRegularMoves(const Color turn, const BoardPieces& board);
Moves GetEnpassantCaptures(const Position enpassant_target, const BoardPieces& board);
Moves GetAllMoves(const BoardState state);
Moves GetLegalMoves(const BoardState state);
Moves GetCastlingMoves(const Color turn, const CastlingRights castling_rights, const BoardPieces& board);
Moves FilterMovesThatLandKingInCheck(Moves& moves, const BoardState state);
Move GetBestMove(const BoardState state);
Moves ApplyPawnProomotionMoves(const Move move);
}