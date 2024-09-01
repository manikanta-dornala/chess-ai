#pragma once
#include "../types/Square.hpp"
#include <iostream>
#include <string>

using namespace std;

const char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

void initializeBoard(Square board[8][8])
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            board[row][col].piece = PieceType::Empty_Piece;
            board[row][col].color = Color::Empty_Color;
        }
    }

    for (int col = 0; col < 8; ++col)
    {
        board[1][col] = {PieceType::Pawn, Color::White};
        board[6][col] = {PieceType::Pawn, Color::Black};
    }

    board[0][0] = {PieceType::Rook, Color::White};
    board[0][7] = {PieceType::Rook, Color::White};
    board[0][1] = {PieceType::Knight, Color::White};
    board[0][6] = {PieceType::Knight, Color::White};
    board[0][2] = {PieceType::Bishop, Color::White};
    board[0][5] = {PieceType::Bishop, Color::White};
    board[0][3] = {PieceType::Queen, Color::White};
    board[0][4] = {PieceType::King, Color::White};

    board[7][0] = {PieceType::Rook, Color::Black};
    board[7][7] = {PieceType::Rook, Color::Black};
    board[7][1] = {PieceType::Knight, Color::Black};
    board[7][6] = {PieceType::Knight, Color::Black};
    board[7][2] = {PieceType::Bishop, Color::Black};
    board[7][5] = {PieceType::Bishop, Color::Black};
    board[7][3] = {PieceType::Queen, Color::Black};
    board[7][4] = {PieceType::King, Color::Black};
}

void copyBoard(const Square original[8][8], Square newBoard[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Square curr    = original[i][j];
            newBoard[i][j] = {curr.piece, curr.color};
        }
    }
}

int numPiecesOnBoard(const Square board[8][8])
{
    int numPieces = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j].piece != PieceType::Empty_Piece)
            {
                numPieces++;
            }
        }
    }
    return numPieces;
}

void printBoard(const Square board[8][8])
{
    for (int row = 7; row >= 0; --row)
    {
        for (int col = 0; col < 8; ++col)
        {
            char pieceChar = ' ';
            switch (board[row][col].piece)
            {
            case PieceType::Pawn:
                pieceChar = 'P';
                break;
            case PieceType::Knight:
                pieceChar = 'N';
                break;
            case PieceType::Bishop:
                pieceChar = 'B';
                break;
            case PieceType::Rook:
                pieceChar = 'R';
                break;
            case PieceType::Queen:
                pieceChar = 'Q';
                break;
            case PieceType::King:
                pieceChar = 'K';
                break;
            default:
                pieceChar = '.';
                break;
            }

            if (board[row][col].color == Color::Black)
            {
                pieceChar = tolower(pieceChar);
            }

            std::cout << pieceChar << " ";
        }
        std::cout << std::endl;
    }
}