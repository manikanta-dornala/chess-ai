#include <iostream>
#include <string>

#include "chessai.hpp"

using namespace std;

int main()
{
    const string fen =
        "r1b2k1r/ppppq3/5N1p/4P2Q/4PP2/1B6/PP5P/n2K2R1 w - - 1 0";
    BoardState state = FEN::GetBoardState(fen);
    Board::printBoard(state.board);
    // Board::GetLegalMoves(turn, castling_rights, enpassant_target, board);
    cout << "------\n";

    for (int i = 0; i < 4; i++)
    {
        auto move = Board::GetBestMove(state);
        if (move.curr.rank == -1)
        {
            cout << "checkmate" << endl;
            return 0;
        }
        state = Board::NewBoardAfterMove(move, state);
        cout << state.turn << " " << move.curr.GetPositionCode() << " "
             << move.type << " " << move.target.GetPositionCode() << "\n";
    }

    return 0;
}