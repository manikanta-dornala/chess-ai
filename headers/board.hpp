#pragma once
#include <iostream>
#include <list>

#include "enums.hpp"
#include "structs.hpp"
#include "utils.hpp"
using namespace std;

namespace Board
{
    // Board
    void InitializeBoard(BoardArray &board);
    void copyBoard(const BoardArray &orignal, BoardArray &newBoard);
    int numPiecesOnBoard(const BoardArray &board);
    const Piece &GetPieceAtPosition(const Position &position,
                                    const BoardArray &board);
    void printBoard(const BoardArray &board);
    bool IsPositionEmpty(const Position &position, const BoardArray &board);
    bool IsKingInCheck(const Color turn, const BoardArray &board);
    bool IsKingInCheckAt(const Color turn,
                         const Position &king_position,
                         const BoardArray &board);
    Position GetKingPosition(const Color turn, const BoardArray &board);
    BoardArray
    NewBoardAfterMove(Move move, Color turn, const BoardArray &board);

    int getSimpleValueForBoard(const Color &turn, const BoardArray &board);
} // namespace Board