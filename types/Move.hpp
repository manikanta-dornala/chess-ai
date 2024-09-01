#pragma once
#include <string>
#include <map>
#include <list>
#include "Piece.hpp"
using namespace std;

enum MoveType
{
    no_move = 0,
    move,
    double_move,
    capture,
    enpassant,
    promote,
    castling
};

struct Move
{
    int currFile;
    int currRank;
    int targetFile;
    int targetRank;
    MoveType type;
};

struct MoveSet
{
    int file;
    int rank;
};

const map<PieceType, list<MoveSet>> PieceMoveSets = {
    {rook, {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}},
    {bishop, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
    {queen, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}},
    {king, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}},
    {knight, {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}}};