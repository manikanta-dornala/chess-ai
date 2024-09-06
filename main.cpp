#include <iostream>
#include <string>

#include "chessai.hpp"

using namespace std;

int eval_move(Move move, Color turn, BoardArray &board)
{
    const int alpha = turn == COLOR_WHITE ? -pow(2, 15) : pow(2, 15);
    const auto new_board = Board::NewBoardAfterMove(move, turn, board);
    int eval = AI::minmax(
        new_board, turn == COLOR_WHITE ? COLOR_BLACK : turn, 3, alpha, -alpha);
    return eval;
}

Move bestMove(const Color &turn,
              const CastlingRights &castling_rights,
              const Position &enpassant_target,
              const BoardArray &board)
{
    auto moves =
        Moves::GetAllMoves(turn, castling_rights, enpassant_target, board);
    moves = Moves::FilterMovesThatLandKingInCheck(moves, turn, board);
    if (moves.size() == 0)
    {
        return {
            .curr = {.rank = -1, .file = -1}
        };
    }
    const int alpha = turn == COLOR_WHITE ? -pow(2, 15) : pow(2, 15);
    vector<int> evals;
    for (const auto move : moves)
    {
        const auto new_board = Board::NewBoardAfterMove(move, turn, board);
        int eval = AI::minmax(new_board,
                              turn == COLOR_WHITE ? COLOR_BLACK : turn,
                              4,
                              alpha,
                              -alpha);
        evals.push_back(eval);
        // cout << turn << " " << move.curr.GetPositionCode() << " " <<
        // move.type
        //      << " " << move.target.GetPositionCode() << " " << eval << "\n";
    }

    // cout << "---" << endl;
    // Board::printBoard(board);
    sort_by_order(moves, evals, false);

    const Move best = moves[0];
    return best;
}

int main()
{
    BoardArray board;
    Board::InitializeBoard(board);
    const string fen =
        "r1b2k1r/ppppq3/5N1p/4P2Q/4PP2/1B6/PP5P/n2K2R1 w - - 1 0";
    FEN::SetBoard(fen, board);
    const CastlingRights &castling_rights = FEN::GetCastlingRights(fen);
    Color turn = FEN::GetCurrentTurn(fen);
    const Position enpassant_target = FEN::GetEnPassantTarget(fen);
    Board::printBoard(board);
    // Moves::GetLegalMoves(turn, castling_rights, enpassant_target, board);
    cout << "------\n";

    for (int i = 0; i < 3; i++)
    {
        auto move = bestMove(turn, castling_rights, enpassant_target, board);
        if (move.curr.rank == -1)
        {
            cout << "checkmate" << endl;
            return 0;
        }
        board = Board::NewBoardAfterMove(move, turn, board);
        turn = turn == COLOR_WHITE ? COLOR_BLACK : COLOR_WHITE;
        cout << turn << " " << move.curr.GetPositionCode() << " " << move.type
             << " " << move.target.GetPositionCode() << "\n";
    }

    // for (const auto move : moves)
    // {
    //     const auto new_board = Board::NewBoardAfterMove(move, turn, board);
    //     int eval = AI::minmax(new_board,
    //                           turn == COLOR_WHITE ? COLOR_BLACK : turn,
    //                           3,
    //                           alpha,
    //                           -alpha);
    //     cout << turn << " " << move.curr.GetPositionCode() << " " <<
    //     move.type
    //          << " " << move.target.GetPositionCode() << " " << eval << "\n";
    // }

    return 0;
}