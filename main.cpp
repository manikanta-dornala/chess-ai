#include <iostream>
#include <string>
#include "game/FEN.hpp"
#include "game/Board.hpp"
#include "game/Moves.hpp"
using namespace std;
int main()
{
	Square board[8][8];
	Board::InitializeBoard(board);
	const string fen = "rnbqkbnr/p1ppp1pp/8/4PpP1/1p6/8/PPPP1P1P/RNBQKBNR w KQkq f6 0 5";
	FEN::SetBoard(fen, board);
	CastlingRights castling_rights = FEN::GetCastlingRights(fen);
	Color		   turn = FEN::GetCurrentTurn(fen);
	Position	   enpassant_target = FEN::GetEnPassantTarget(fen);
	Board::printBoard(board);
	cout << Moves::GetLegalMoves(turn, castling_rights, enpassant_target, board).size() << "\n";
	return 0;
}