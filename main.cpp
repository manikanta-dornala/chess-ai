#include <iostream>
#include <string>
#include "game/game.hpp"
#include "utils/utils.hpp"
using namespace std;
int main()
{
	Square board[8][8];
	InitializeBoard(board);
	const string fen = "rnbqkbnr/p1ppp1pp/8/4PpP1/1p6/8/PPPP1P1P/RNBQKBNR w KQkq f6 0 5";
	SetBoardFromFEN(fen, board);
	CastlingRights castling_rights = GetCastlingRightsFromFEN(fen);
	Color		   turn = GetCurrentTurnFromFEN(fen);
	SquarePosition enpassant_target = GetEnPassantTargetFromFEN(fen);
	printBoard(board);
	cout << GetLegalMoves(turn, castling_rights, enpassant_target, board).size() << "\n";
	return 0;
}