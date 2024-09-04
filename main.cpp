#include <iostream>
#include <string>

#include "headers/chessai.hpp"

using namespace std;

int main()
{
    BoardArray board;
    Board::InitializeBoard(board);
    const string fen =
        "rnbq1rk1/pppp1ppp/4p3/2bnN2Q/4P3/3B1P2/PPPP2PP/RNB1K2R w KQ - 1 7";
    FEN::SetBoard(fen, board);
    const CastlingRights &castling_rights = FEN::GetCastlingRights(fen);
    const Color turn = FEN::GetCurrentTurn(fen);
    const Position enpassant_target = FEN::GetEnPassantTarget(fen);
    Board::printBoard(board);
    Moves::GetLegalMoves(turn, castling_rights, enpassant_target, board);
    return 0;
}