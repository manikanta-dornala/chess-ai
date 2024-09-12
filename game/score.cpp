#include "../chessai.hpp"

namespace Board {

const map<PieceType, int> PieceValues = {
    { PIECETYPE_NIL, 0 },
    { PIECETYPE_PAWN, 100 },
    { PIECETYPE_KNIGHT, 300 },
    { PIECETYPE_BISHOP, 300 },
    { PIECETYPE_ROOK, 500 },
    { PIECETYPE_QUEEN, 900 },
    { PIECETYPE_KING, 0 },
};

int getSimpleValueForBoard(const BoardArray& board)
{
    int score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            const Piece piece = board[i][j];
            const int sign = piece.color == COLOR_WHITE ? 1 : -1;
            score += sign * PieceValues.at(piece.type);
        }
    }
    return score;
}

int EvaluateMoveWithSimpleScoreLookup(Move move, const BoardState state)
{
    const auto new_state = Board::NewBoardAfterMove(move, state);
    return Board::getSimpleValueForBoard(new_state.board);
}

int EvaluateMoveWithSomeHeuristics(Move move, const BoardState state)
{
    int score = 0;
    const int sign = move.piece.color == COLOR_WHITE ? -1 : 1;
    if (move.captured_piece.type != PIECETYPE_NIL && move.type == MOVETYPE_CAPTURE) {
        score += sign * 10 * ((PieceValues.at(move.captured_piece.type)));
    }
    const auto new_state = Board::NewBoardAfterMove(move, state);
    score += Board::getSimpleValueForBoard(new_state.board);
    return score;
}

MinMaxEval EvaluateMoveWithMinMax(Move move,
    const BoardState state,
    int depth)
{
    const auto new_state = Board::NewBoardAfterMove(move, state);
    const int alpha = new_state.turn == COLOR_WHITE ? INT_MAX : -INT_MAX;
    MinMaxEval eval = AI::minmax(new_state, depth, alpha, -alpha);
    return eval;
}
} // namespace Board