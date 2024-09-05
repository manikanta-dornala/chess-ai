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
                // if (IsKingInCheckAt(piece.color, {.rank = i, .file = j},
                // board))
                // {
                //     return -sign * 1024;
                // }
                score += sign * PieceValues.at(piece.type);
            }
        }
        return score;
    }

    int EvaluateMove(Move move, Color turn, BoardArray board)
    {
        const BoardArray new_board =
            Board::NewBoardAfterMove(move, turn, board);
        return Board::getSimpleValueForBoard(new_board);
    }
} // namespace Board