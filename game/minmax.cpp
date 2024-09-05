#include "../chessai.hpp"

namespace AI
{
    int minmax(const BoardArray &board,
               const Color &turn,
               const int depth,
               int alpha,
               int beta)
    {
        if (depth == 0)
        {
            // cout << depth << "--\n";
            // Board::printBoard(board);
            return Board::getSimpleValueForBoard(board);
        }

        vector<Move> moves = Moves::GetRegularMoves(turn, board);
        moves = Moves::FilterMovesThatLandKingInCheck(moves, turn, board);

        if (Board::IsKingInCheck(turn, board) && moves.size() == 0)
        {
            // cout << depth << "--\n";
            // Board::printBoard(board);
            return turn == COLOR_WHITE ? -9999 : 9999;
        }
        vector<int> evals;
        for (auto move : moves)
        {
            evals.push_back(Board::EvaluateMove(move, turn, board));
        }
        sort_by_order(moves, evals, false);
        if (turn == COLOR_WHITE)
        {
            int max_eval = -pow(2, 10);
            for (const Move move : moves)
            {
                const BoardArray new_board =
                    Board::NewBoardAfterMove(move, COLOR_WHITE, board);
                int eval =
                    minmax(new_board, COLOR_BLACK, depth - 1, alpha, beta);

                // cout << turn << " " << move.curr.GetPositionCode() << " "
                //      << move.target.GetPositionCode() << " " << eval << "\n";
                max_eval = max(eval, max_eval);
                alpha = max(alpha, eval);
                if (beta <= alpha)
                {
                    break;
                }
            }
            return max_eval;
        }
        if (turn == COLOR_BLACK)
        {
            int min_eval = pow(2, 10);
            for (const Move move : moves)
            {
                const BoardArray new_board =
                    Board::NewBoardAfterMove(move, COLOR_BLACK, board);
                int eval =
                    minmax(new_board, COLOR_WHITE, depth - 1, alpha, beta);
                // cout << move.curr.GetPositionCode() << " "
                //      << move.target.GetPositionCode() << " " << eval << "\n";
                min_eval = min(eval, min_eval);
                beta = min(beta, eval);
                if (beta <= alpha)
                {
                    break;
                }
            }
            return min_eval;
        }

        return 0;
    }
} // namespace AI