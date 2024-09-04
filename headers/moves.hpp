#pragma once
#include <iostream>
#include <list>

#include "enums.hpp"
#include "structs.hpp"
using namespace std;

namespace Moves
{
    vector<Move> GetMovesForPieceAt(const Position &position,
                                    const BoardArray &board);
    vector<Move> GetRegularMoves(const Color &turn, const BoardArray &board);
    vector<Move> GetEnpassantCaptures(const Position &enapassant_target,
                                      const BoardArray &board);
    vector<Move> GetLegalMoves(const Color &turn,
                               const CastlingRights &castling_rights,
                               const Position &enpassant_target,
                               const BoardArray &board);
    vector<Move> GetCastlingMoves(const Color &turn,
                                  const CastlingRights &castling_rights,
                                  const BoardArray &board);
    vector<Move> FilterMovesThatLandKingInCheck(vector<Move> moves,
                                                const Color turn,
                                                const BoardArray &board);
} // namespace Moves