#include <iostream>
#include <string>

#include "chessai.hpp"

using namespace std;

int main()
{
    // const string fen = "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - ";
    // const string fen =
    //     "rnbqkbnr/pppppppp/8/8/3P4/8/PPP1PPPP/RNBQKBNR b KQkq d3 0 2";
    // const string fen =
    //     "rnbqkbnr/pppp1ppp/8/4p3/3P4/8/PPP1PPPP/RNBQKBNR w KQkq e6 0 2";
    // const string fen =
    //     "1Nbqkb1r/2pppppp/7n/2P5/8/1n2P3/PP1P1PPP/R1BQKBNR w KQk - 1 9";
    const auto fen = "5Kbk/6pp/6P1/8/8/8/8/7R w - -"; // Mate in two
    BoardState state = FEN::GetBoardState(fen);
    Board::printBoard(state.board);
    // Board::GetLegalMoves(turn, castling_rights, enpassant_target, board);
    cout << "------\n";

    for (int i = 0; i < 10; i++)
    {
        auto move = Board::GetBestMove(state);

        cout << state.turn << " " << move.curr.GetPositionCode() << " "
             << move.type << " " << move.target.GetPositionCode() << "\n";
        if (move.curr.rank == -1)
        {
            cout << "checkmate" << endl;
            return 0;
        }
        state = Board::NewBoardAfterMove(move, state);
        Board::printBoard(state.board);
    }

    return 0;
}