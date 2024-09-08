#include "../chessai.hpp"

namespace Board
{

    const map<PieceType, int> PieceValues = {
        {PIECETYPE_NIL,    0},
        {PIECETYPE_PAWN,   1},
        {PIECETYPE_KNIGHT, 3},
        {PIECETYPE_BISHOP, 3},
        {PIECETYPE_ROOK,   5},
        {PIECETYPE_QUEEN,  9},
        {PIECETYPE_KING,   0},
    };

    int getSimpleValueForBoard(const BoardArray &board)
    {
        int score = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                const Piece piece = board[i][j];
                const int sign = piece.color == COLOR_WHITE ? 1 : -1;
                score += sign * PieceValues.at(piece.type);
            }
        }
        return score;
    }

    int EvaluateMoveWithScoreLookup(Move move, const BoardState &state)
    {
        const auto new_state = Board::NewBoardAfterMove(move, state);
        return Board::getSimpleValueForBoard(new_state.board);
    }

    int EvaluateMoveWithMinMax(Move move, const BoardState &state)
    {
        const int alpha = state.turn == COLOR_WHITE ? pow(2, 15) : -pow(2, 15);
        const auto new_state = Board::NewBoardAfterMove(move, state);
        int eval = AI::minmax(new_state, 3, alpha, -alpha);
        return eval;
    }
} // namespace Board