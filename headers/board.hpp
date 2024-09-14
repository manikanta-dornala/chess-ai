#pragma once
#include <iostream>
#include <list>

#include "enums.hpp"
#include "structs.hpp"
#include "utils.hpp"
using namespace std;

namespace Board {

void InitializeBoard(BoardPieces& board);
void copyBoard(const BoardPieces& orignal, BoardPieces& newBoard);
void PrintBoard(const BoardPieces& board);

int numPiecesOnBoard(const BoardPieces& board);
int getSimpleValueForBoard(const BoardPieces& board);

Piece GetPieceAtPosition(const Position position, const BoardPieces& board);

bool IsPositionEmpty(const Position position, const BoardPieces& board);
bool IsKingInCheck(const Color turn, const BoardPieces& board);
bool IsKingInCheckAt(const Color turn, const Position king_position, const BoardPieces& board);

Position GetKingPosition(const Color turn, const BoardPieces& board);

BoardState NewBoardAfterMove(Move move, const BoardState state);

int EvaluateMoveWithSimpleScoreLookup(Move move, const BoardState state);
int EvaluateMoveWithSomeHeuristics(Move move, const BoardState state);
MinMaxEval EvaluateMoveWithMinMax(Move move, const BoardState state, int depth);

BoardHeatMap GetAttackMapForTurn(const Color turn, const BoardState state);

}