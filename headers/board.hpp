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
    const Piece GetPieceAtPosition(const Position position,
                                   const BoardArray &board);
    void printBoard(const BoardArray &board);
    bool IsPositionEmpty(const Position position, const BoardArray &board);
    bool IsKingInCheck(const Color turn, const BoardArray &board);
    bool IsKingInCheckAt(const Color turn,
                         const Position king_position,
                         const BoardArray &board);
    Position GetKingPosition(const Color turn, const BoardArray &board);
    BoardState NewBoardAfterMove(Move move, const BoardState state);

    int getSimpleValueForBoard(const BoardArray &board);
    int EvaluateMoveWithSimpleScoreLookup(Move move, const BoardState state);
    int EvaluateMoveWithSomeHeuristics(Move move, const BoardState state);
    MinMaxEval
    EvaluateMoveWithMinMax(Move move, const BoardState state, int depth);
    constexpr int RANK_1 = 0;
    constexpr int RANK_2 = 1;
    constexpr int RANK_3 = 2;
    constexpr int RANK_4 = 3;
    constexpr int RANK_5 = 4;
    constexpr int RANK_6 = 5;
    constexpr int RANK_7 = 6;
    constexpr int RANK_8 = 7;

    constexpr int FILE_a = 0;
    constexpr int FILE_b = 1;
    constexpr int FILE_c = 2;
    constexpr int FILE_d = 3;
    constexpr int FILE_e = 4;
    constexpr int FILE_f = 5;
    constexpr int FILE_g = 6;
    constexpr int FILE_h = 7;
} // namespace Board