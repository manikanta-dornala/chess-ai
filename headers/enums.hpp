#pragma once

enum Color { COLOR_NIL = 0,
    COLOR_WHITE,
    COLOR_BLACK };

enum MoveType {
    MOVETYPE_NIL = 0,
    MOVETYPE_MOVE,
    MOVETYPE_DOUBLE_MOVE,
    MOVETYPE_CAPTURE,
    MOVETYPE_ENPASSANT,
    MOVETYPE_PROMOTE,
    MOVETYPE_CASTLING
};

enum PieceType {
    PIECETYPE_NIL = 0,
    PIECETYPE_PAWN,
    PIECETYPE_KNIGHT,
    PIECETYPE_BISHOP,
    PIECETYPE_ROOK,
    PIECETYPE_QUEEN,
    PIECETYPE_KING
};

constexpr int RANK_nil = -1;
constexpr int RANK_1 = 0;
constexpr int RANK_2 = 1;
constexpr int RANK_3 = 2;
constexpr int RANK_4 = 3;
constexpr int RANK_5 = 4;
constexpr int RANK_6 = 5;
constexpr int RANK_7 = 6;
constexpr int RANK_8 = 7;

constexpr int FILE_nil = -1;
constexpr int FILE_a = 0;
constexpr int FILE_b = 1;
constexpr int FILE_c = 2;
constexpr int FILE_d = 3;
constexpr int FILE_e = 4;
constexpr int FILE_f = 5;
constexpr int FILE_g = 6;
constexpr int FILE_h = 7;