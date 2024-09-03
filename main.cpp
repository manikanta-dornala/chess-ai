#include "game/Board.hpp"
#include "game/FEN.hpp"
#include "game/Moves.hpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	Square board[8][8];
	Board::InitializeBoard(board);
	string fen = "rnbqkbnr/pp1pp1pp/8/4PpP1/2p5/8/PPPP1P1P/RNBQKBNR w KQkq f6 0 4";
	FEN::SetBoard(fen, board);
	CastlingRights castling_rights = FEN::GetCastlingRights(fen);
	Color		   turn = FEN::GetCurrentTurn(fen);
	Position	   enpassant_target = FEN::GetEnPassantTarget(fen);
	Board::printBoard(board);
	Moves::GetLegalMoves(turn, castling_rights, enpassant_target, board);
	return 0;
}