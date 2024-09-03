#include "../headers/chessai.hpp"

namespace Board
{

    const map<PieceType, int> PieceValues = {
        { PIECETYPE_NIL, 0 },
        { PIECETYPE_PAWN, 1 },
        { PIECETYPE_KNIGHT, 3 },
        { PIECETYPE_BISHOP, 3 },
        { PIECETYPE_ROOK, 5 },
        { PIECETYPE_QUEEN, 9 },
        { PIECETYPE_KING, 9 },
    };

    const int CurrKingInCheck = -9999999;
    const int OpponentKingInCheck = 25;

    int getSimpleValueForBoard(const Color& turn, const BoardArray& board)
    {
        int score = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                const Piece piece = board[i][j];
                const int   sign = piece.color == turn ? 1 : -1;
                score += sign * PieceValues.at(piece.type);
                if (piece.type == PIECETYPE_KING)
                {
                    if (IsKingInCheckAt(turn, { .rank = i, .file = j }, board))
                    {
                        score += piece.color == turn ? CurrKingInCheck : OpponentKingInCheck;
                    }
                }
            }
        }
        return score;
    }
} // namespace Board