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
	void  copyBoard(Square original[8][8], Square newBoard[8][8]);
	int	  numPiecesOnBoard(Square board[8][8]);
	Piece GetPieceAtPosition(Position position, Square board[8][8]);
	void  printBoard(Square board[8][8]);
	float getScoreForBoard(Square board[8][8], Color turn);
} // namespace Board