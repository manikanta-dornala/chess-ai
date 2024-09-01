#pragma once
#include "Piece.hpp"
#include <list>
#include <map>
#include <string>
#include <vector>
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
    SquarePosition curr;
    SquarePosition target;
    int            targetRank;
    MoveType       type;
};


// Define vectors of MoveSet for each piece type
const vector<SquarePosition> rookMoves = {
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<SquarePosition> bishopMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1}
};
const vector<SquarePosition> queenMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<SquarePosition> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<SquarePosition> knightMoves = {
    {2,  1 },
    {2,  -1},
    {-2, 1 },
    {-2, -1},
    {1,  2 },
    {1,  -2},
    {-1, 2 },
    {-1, -2}
};

// Initialize the map using vectors
const map<PieceType, vector<SquarePosition>> PieceMoveSets = {
    {PieceType::Rook,   rookMoves  },
    {PieceType::Bishop, bishopMoves},
    {PieceType::Queen,  queenMoves },
    {PieceType::King,   kingMoves  },
    {PieceType::Knight, knightMoves}
};