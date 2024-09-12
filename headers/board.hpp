#pragma once
#include <iostream>
#include <list>

#include "enums.hpp"
#include "structs.hpp"
#include "utils.hpp"
using namespace std;

namespace Board {

void InitializeBoard(BoardArray& board);
void copyBoard(const BoardArray& orignal, BoardArray& newBoard);
void PrintBoard(const BoardArray& board);

int numPiecesOnBoard(const BoardArray& board);
int getSimpleValueForBoard(const BoardArray& board);

Piece GetPieceAtPosition(const Position position, const BoardArray& board);

bool IsPositionEmpty(const Position position, const BoardArray& board);
bool IsKingInCheck(const Color turn, const BoardArray& board);
bool IsKingInCheckAt(const Color turn, const Position king_position, const BoardArray& board);

Position GetKingPosition(const Color turn, const BoardArray& board);

BoardState NewBoardAfterMove(Move move, const BoardState state);

int EvaluateMoveWithSimpleScoreLookup(Move move, const BoardState state);
int EvaluateMoveWithSomeHeuristics(Move move, const BoardState state);
MinMaxEval EvaluateMoveWithMinMax(Move move, const BoardState state, int depth);

}