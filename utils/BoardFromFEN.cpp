#pragma once
#include "../game/Board.cpp"
#include "../types/CastlingRights.cpp"
#include "../types/Square.cpp"
#include <iostream>
#include <string>
using namespace std;

void setBoardFromFEN(const string& fen, Square board[8][8])
{
    // Clear the board
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j].piece.type  = PieceType::Empty_Piece;
            board[i][j].piece.color = Color::Empty_Color;
        }
    }

    int rank = 7;
    int file = 0;
    int i    = 0;

    while (fen[i] != ' ')
    {
        char c = fen[i];
        if (c == '/')
        {
            // when there's a / a new rank starts
            rank--;
            file = 0;
        }
        else if (isdigit(c))
        {
            // if we see a number start counting empty squares
            // the number here is number of empty squares
            // we can move that many files forward
            file += c - '0';
        }
        else
        {
            Color     color         = isupper(c) ? Color::White : Color::Black;
            PieceType pieceType     = PieceTypeMap.at(tolower(c));
            board[rank][file].piece = {pieceType, color};
            file++;
        }
        i++;
    }
}

Color getCurrentTurn(const string& fen)
{
    int i = 0;

    while (fen[i] != ' ')
    {
        i++;
    }
    if (fen[i + 1] == 'w')
        return Color::White;
    if (fen[i + 1] == 'b')
        return Color::Black;
    return Color::Empty_Color;
}

CastlingRights getCastlingRights(const string& fen)
{
    int i = 0;
    while (fen[i] != ' ')
    {
        i++;
    }
    i++;
    while (fen[i] != ' ')
    {
        i++;
    }
    CastlingRights rights;
    rights.white_king_side  = fen[i + 1] == 'K';
    rights.white_queen_side = fen[i + 2] == 'Q';
    rights.black_king_side  = fen[i + 3] == 'k';
    rights.black_queen_side = fen[i + 4] == 'q';
    return rights;
}

SquarePosition getEnPassantTarget(const string& fen)
{
    int i = 0;
    while (fen[i] != ' ')
    {
        i++;
    }
    i++;
    while (fen[i] != ' ')
    {
        i++;
    }
    i++;
    while (fen[i] != ' ')
    {
        i++;
    }
    i++;
    if (fen[i] == '-')
    {
        return {-1, -1};
    }
    int file = fen[i] - 'a';
    int rank = fen[i + 1] - '1';
    return {file, rank};
}