
#include "../chessai.hpp"

using namespace std;

char Piece::GetPieceCode() const
{
    char code = ' ';
    switch (this->type)
    {
        case PIECETYPE_PAWN:
            code = 'p';
            break;
        case PIECETYPE_KNIGHT:
            code = 'n';
            break;
        case PIECETYPE_BISHOP:
            code = 'b';
            break;
        case PIECETYPE_ROOK:
            code = 'r';
            break;
        case PIECETYPE_QUEEN:
            code = 'q';
            break;
        case PIECETYPE_KING:
            code = 'k';
            break;
        default:
            code = '.';
            break;
    }
    return this->color == COLOR_WHITE ? toupper(code) : tolower(code);
}
