#pragma once
#include <iostream>
#include <list>
#include "../utils/utils.hpp"
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
using namespace std;

namespace Board
{
	// Board
	void  InitializeBoard(Square board[8][8]);
	void  copyBoard(const Square original[8][8], Square newBoard[8][8]);
	int	  numPiecesOnBoard(const Square board[8][8]);
	Piece GetPieceAtPosition(Position position, const Square board[8][8]);
	void  printBoard(const Square board[8][8]);
	float getScoreForBoard(const Square board[8][8], Color turn);
} // namespace Board