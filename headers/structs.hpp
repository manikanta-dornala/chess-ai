#pragma once
#include "enums.hpp"
using namespace std;

class CastlingRights {
public:
    bool white_king_side = false;
    bool white_queen_side = false;
    bool black_king_side = false;
    bool black_queen_side = false;
};

class Position {
public:
    int rank = RANK_nil;
    int file = FILE_nil;

    bool IsValidPosition() const;
    string GetPositionCode() const;
};

vector<Position>& GetPieceMoveDestinations(PieceType& piece_type);

class Piece {
public:
    PieceType type = PIECETYPE_NIL;
    Color color = COLOR_NIL;
    char GetPieceCode() const;
};

using BoardArray = std::array<std::array<Piece, 8>, 8>;

class Move {
public:
    Position curr;
    Position target;
    Piece piece;
    Piece captured_piece;
    Piece promoted_piece;
    MoveType type = MOVETYPE_NIL;
    string GetChars();
};

using Moves = vector<Move>;

class BoardState {
public:
    BoardArray board;
    CastlingRights castling_rights;
    Position enpassant_target;
    Color turn = COLOR_NIL;
};

class MinMaxEval {
public:
    int value = 0;
    int num_moves_evaluated = 0;
};