#include "Board.cpp"
#include "Moves.cpp"
#include <iostream>
using namespace std;
int main()
{
    Square         board[8][8];
    CastlingRights castlingRights;
    initializeBoard(board);
    cout << "hi\n";
    printBoard(board);
    cout << GetLegalMoves(board, white, castlingRights).size() << "\n";
    return 0;
}