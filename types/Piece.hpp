#pragma once
#include <map>
using namespace std;
enum PieceType
{
    Empty_Piece = 0,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};

const map<char, PieceType> PieceTypeMap = {
    {'p', Pawn},
    {'n', Knight},
    {'b', Bishop},
    {'r', Rook},
    {'q', Queen},
    {'k', King}
};