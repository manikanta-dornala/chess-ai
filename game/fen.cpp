#include "../headers/chessai.hpp"
using namespace std;
namespace FEN
{
    map<char, PieceType> PieceTypeMap = {
        { 'p', PIECETYPE_PAWN },
        { 'n', PIECETYPE_KNIGHT },
        { 'b', PIECETYPE_BISHOP },
        { 'r', PIECETYPE_ROOK },
        { 'q', PIECETYPE_QUEEN },
        { 'k', PIECETYPE_KING }
    };

    void SetBoard(const string& fen, BoardArray& board)
    {
        // Clear the board
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                board[i][j].type = PIECETYPE_NIL;
                board[i][j].color = COLOR_NIL;
            }
        }

        int rank = 7;
        int file = 0;
        int i = 0;

        while (fen[i] != ' ')
        {
            char c = fen[i];
            if (c == '/')
            {
                // when there's a / a new rank starts
                rank--;
                file = 0;
            }
            else if (isdigit(c))
            {
                // if we see a number start counting empty Pieces
                // the number here is number of empty Pieces
                // we can move that many files forward
                file += c - '0';
            }
            else
            {
                Color     color = isupper(c) ? COLOR_WHITE : COLOR_BLACK;
                PieceType pieceType = PieceTypeMap.at(tolower(c));
                board[rank][file] = { pieceType, color };
                file++;
            }
            i++;
        }
    }

    Color GetCurrentTurn(const string& fen)
    {
        int i = 0;

        while (fen[i] != ' ')
        {
            i++;
        }
        if (fen[i + 1] == 'w')
            return COLOR_WHITE;
        if (fen[i + 1] == 'b')
            return COLOR_BLACK;
        return COLOR_NIL;
    }

    CastlingRights GetCastlingRights(const string& fen)
    {
        int i = 0;
        while (fen[i] != ' ')
        {
            i++;
        }
        i++;
        while (fen[i] != ' ')
        {
            i++;
        }
        CastlingRights rights;
        rights.white_king_side = fen[i + 1] == 'K';
        rights.white_queen_side = fen[i + 2] == 'Q';
        rights.black_king_side = fen[i + 3] == 'k';
        rights.black_queen_side = fen[i + 4] == 'q';
        return rights;
    }

    Position GetEnPassantTarget(const string& fen)
    {
        int i = 0;
        while (fen[i] != ' ')
        {
            i++;
        }
        i++;
        while (fen[i] != ' ')
        {
            i++;
        }
        i++;
        while (fen[i] != ' ')
        {
            i++;
        }
        i++;
        if (fen[i] == '-')
        {
            return { -1, -1 };
        }
        int file = fen[i] - 'a';
        int rank = fen[i + 1] - '1';
        return { file, rank };
    }
} // namespace FEN
