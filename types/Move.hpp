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

// Define vectors of MoveSet for each piece type
const vector<MoveSet> rookMoves = {
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> bishopMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1}
};
const vector<MoveSet> queenMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> kingMoves = {
    {1,  1 },
    {1,  -1},
    {-1, 1 },
    {-1, -1},
    {0,  1 },
    {0,  -1},
    {1,  0 },
    {-1, 0 }
};
const vector<MoveSet> knightMoves = {
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
const map<PieceType, vector<MoveSet>> PieceMoveSets = {
    {PieceType::rook,   rookMoves  },
    {PieceType::bishop, bishopMoves},
    {PieceType::queen,  queenMoves },
    {PieceType::king,   kingMoves  },
    {PieceType::knight, knightMoves}
};