

#include "../chessai.hpp"

using namespace std;

string Position::GetPositionCode() const
{
    string result = "..";
    result[0] = 'a' + this->file;
    result[1] = '1' + this->rank;
    return result;
}

bool Position::IsValidPosition() const
{
    return this->rank >= 0 && this->rank <= 7 && this->file >= 0 && this->file <= 7;
}

vector<Position> rook_moveset = { { .rank = 0, .file = 1 },
    { .rank = 0, .file = -1 },
    { .rank = 1, .file = 0 },
    { .rank = -1, .file = 0 } };
vector<Position> bishop_moveset = { { .rank = 1, .file = 1 },
    { .rank = 1, .file = -1 },
    { .rank = -1, .file = 1 },
    { .rank = -1, .file = -1 } };
vector<Position> knight_moveset = {
    { .rank = 2, .file = 1 }, { .rank = 2, .file = -1 }, { .rank = -2, .file = 1 },
    { .rank = -2, .file = -1 }, { .rank = 1, .file = 2 }, { .rank = 1, .file = -2 },
    { .rank = -1, .file = 2 }, { .rank = -1, .file = -2 }
};
vector<Position> queen_moveset = Concatenate(rook_moveset, bishop_moveset);
vector<Position> nil_moveset = vector<Position>();
vector<Position>& GetPieceMoveDestinations(PieceType& piece_type)
{
    switch (piece_type) {
    case PIECETYPE_ROOK:
        return rook_moveset;
    case PIECETYPE_BISHOP:
        return bishop_moveset;
    case PIECETYPE_KNIGHT:
        return knight_moveset;
    case PIECETYPE_QUEEN:
        return queen_moveset;
    case PIECETYPE_KING:
        return queen_moveset;
    default:
        return nil_moveset;
    };
}
