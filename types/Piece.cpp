#pragma once
#include "Color.cpp"
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
    {'p', PieceType::Pawn  },
    {'n', PieceType::Knight},
    {'b', PieceType::Bishop},
    {'r', PieceType::Rook  },
    {'q', PieceType::Queen },
    {'k', PieceType::King  }
};

struct Piece
{
    PieceType type;
    Color     color;
};

char getPieceCode(Piece piece)
{
    char code = ' ';
    switch (piece.type)
    {
    case PieceType::Pawn:
        code = 'p';
        break;
    case PieceType::Knight:
        code = 'n';
        break;
    case PieceType::Bishop:
        code = 'b';
        break;
    case PieceType::Rook:
        code = 'r';
        break;
    case PieceType::Queen:
        code = 'q';
        break;
    case PieceType::King:
        code = 'k';
        break;
    default:
        code = '.';
        break;
    }
    return piece.color == Color::White ? toupper(code) : tolower(code);
}
