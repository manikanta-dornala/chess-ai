#pragma once
#include "Color.hpp"
#include "Piece.hpp"

struct Square
{
    PieceType piece;
    Color     color;
};

struct SquarePosition
{
    int file;
    int rank;
};