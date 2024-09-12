#include "../chessai.hpp"

namespace AI {

MinMaxEval minmax(const BoardState state,
    const int depth,
    int alpha,
    int beta)
{
    if (depth == 0) {
        return { .value = Board::getSimpleValueForBoard(state.board),
            .num_moves_evaluated = 1 };
    }

    Moves moves = Board::GetRegularMoves(state.turn, state.board);
    moves = Board::FilterMovesThatLandKingInCheck(moves, state);

    if (Board::IsKingInCheck(state.turn, state.board) && moves.size() == 0) {
        // Checkmate
        auto value = state.turn == COLOR_WHITE ? -INT_MAX : INT_MAX;
        return { .value = value, .num_moves_evaluated = 1 };
    }

    vector<int> evals;
    for (auto move : moves) {
        // evals.push_back(Board::EvaluateMoveWithSomeHeuristics(move,
        // state));
        evals.push_back(Board::EvaluateMoveWithSimpleScoreLookup(move, state));
    }
    sort_by_order(moves, evals, false);

    int max_eval_value = -INT_MAX;

    MinMaxEval last_eval;
    int total_moves = 0;
    int min_eval_value = INT_MAX;

    for (const auto move : moves) {
        const BoardState new_state = Board::NewBoardAfterMove(move, state);
        auto eval = minmax(new_state, depth - 1, alpha, beta);
        total_moves += eval.num_moves_evaluated;
        if (state.turn == COLOR_WHITE) {
            max_eval_value = max(eval.value, max_eval_value);
            if (max_eval_value == eval.value) {
                last_eval = eval;
            }

            alpha = max(alpha, eval.value);
            if (beta <= alpha) {
                break;
            }
        }
        if (state.turn == COLOR_BLACK) {
            min_eval_value = min(eval.value, min_eval_value);
            if (min_eval_value == eval.value)
                last_eval = eval;
            beta = min(beta, eval.value);
            if (beta <= alpha) {
                break;
            }
        }
    }
    last_eval.num_moves_evaluated = total_moves;
    // last_eval.value = last_eval.value / depth;
    // if (depth == 1)
    //     cout << depth << " " << last_eval.num_moves_evaluated << endl;
    return last_eval;
}
} // namespace AI