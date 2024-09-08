#include "../chessai.hpp"

namespace AI
{
    int minmax(const BoardState &state, const int depth, int alpha, int beta)
    {
        if (depth == 0)
        {
            return Board::getSimpleValueForBoard(state.board);
        }

        Moves moves = Board::GetRegularMoves(state.turn, state.board);
        moves = Board::FilterMovesThatLandKingInCheck(moves, state);

        if (Board::IsKingInCheck(state.turn, state.board) && moves.size() == 0)
        {
            // Checkmate
            return state.turn == COLOR_WHITE ? -9999 : 9999;
        }

        vector<int> evals;
        for (auto move : moves)
        {
            evals.push_back(Board::EvaluateMoveWithScoreLookup(move, state));
        }
        sort_by_order(moves, evals, false);

        if (state.turn == COLOR_WHITE)
        {
            int max_eval = -1024;
            for (const Move move : moves)
            {
                const BoardState new_state =
                    Board::NewBoardAfterMove(move, state);
                int eval = minmax(new_state, depth - 1, alpha, beta);

                max_eval = max(eval, max_eval);
                alpha = max(alpha, eval);
                if (beta <= alpha)
                {
                    break;
                }
            }
            return max_eval;
        }
        if (state.turn == COLOR_BLACK)
        {
            int min_eval = 1024;
            for (const Move move : moves)
            {
                const BoardState new_state =
                    Board::NewBoardAfterMove(move, state);
                int eval = minmax(new_state, depth - 1, alpha, beta);
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