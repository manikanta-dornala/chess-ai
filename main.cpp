#include "utils/Board.cpp"
#include "utils/BoardFromFEN.cpp"
#include "utils/Moves.cpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    Square board[8][8];
    initializeBoard(board);
    const string fen = "rnbqkbnr/ppp1pppp/8/3p4/4P3/8/PPPP1PPP/RNBQKBNR w KQkq d6 0 2";
    setBoardFromFEN(fen, board);
    CastlingRights castlingRights  = getCastlingRights(fen);
    Color          turn            = getCurrentTurn(fen);
    SquarePosition enpassantTarget = getEnPassantTarget(fen);
    printBoard(board);
    cout << GetLegalMoves(board, turn, castlingRights).size() << "\n";
    return 0;
}