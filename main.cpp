#include "utils/Board.cpp"
#include "utils/BoardFromFEN.cpp"
#include "utils/Moves.cpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    Square         board[8][8];
    CastlingRights castlingRights;
    const string   fen = "rnbqkbnr/pp3ppp/2p1P3/3p4/3P4/8/PPP1P1PP/RNBQKBNR b KQkq - 0 6";
    setBoardFromFEN(fen, board);
    castlingRights = getCastlingRights(fen);
    // cout << "hi\n";
    // cout << castlingRights.white_king_side << castlingRights.white_queen_side
    //      << castlingRights.black_king_side << castlingRights.black_queen_side << "\n";
    SquarePosition enpassantTarget = getEnPassantTarget(fen);
    // cout << files[enpassantTarget.file] << enpassantTarget.rank + 1 << "\n";
    printBoard(board);
    cout << GetLegalMoves(board, Color::White, castlingRights).size() << "\n";
    return 0;
}