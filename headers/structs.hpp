#pragma once
#include "enums.hpp"
using namespace std;

struct CastlingRights
{
    bool white_king_side;
    bool white_queen_side;
    bool black_king_side;
    bool black_queen_side;
};

class Position
{
  public:
    int rank;
    int file;

    bool IsValidPosition() const;
    string GetPositionCode() const;
};

vector<Position> &GetPieceMoveDestinations(PieceType &piece_type);

class Piece
{
  public:
    PieceType type;
    Color color;
    char GetPieceCode() const;
};

using BoardArray = std::array<std::array<Piece, 8>, 8>;

struct Move
{
    Position curr;
    Position target;
    Piece Piece;
    MoveType type;
    string getPGN();
};

struct BoardState
{
    BoardArray board;
    CastlingRights castling_rights;
    Position enpassant_target;
    Color turn;
};

// expr Piece DefaultPiece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };
