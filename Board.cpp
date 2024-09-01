#pragma once
#include "types/Square.hpp"
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
            board[row][col].piece = no_piece;
            board[row][col].color = no_color;
        }
    }

    for (int col = 0; col < 8; ++col)
    {
        board[1][col] = {pawn, white};
        board[6][col] = {pawn, black};
    }

    board[0][0] = {rook, white};
    board[0][7] = {rook, white};
    board[0][1] = {knight, white};
    board[0][6] = {knight, white};
    board[0][2] = {bishop, white};
    board[0][5] = {bishop, white};
    board[0][3] = {queen, white};
    board[0][4] = {king, white};

    board[7][0] = {rook, black};
    board[7][7] = {rook, black};
    board[7][1] = {knight, black};
    board[7][6] = {knight, black};
    board[7][2] = {bishop, black};
    board[7][5] = {bishop, black};
    board[7][3] = {queen, black};
    board[7][4] = {king, black};
}

void copyBoard(const Square original[8][8], Square newBoard[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Square curr = original[i][j];
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
            if (board[i][j].piece != no_piece)
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
            case pawn:
                pieceChar = 'P';
                break;
            case knight:
                pieceChar = 'N';
                break;
            case bishop:
                pieceChar = 'B';
                break;
            case rook:
                pieceChar = 'R';
                break;
            case queen:
                pieceChar = 'Q';
                break;
            case king:
                pieceChar = 'K';
                break;
            default:
                pieceChar = '.';
                break;
            }

            if (board[row][col].color == black)
            {
                pieceChar = tolower(pieceChar);
            }

            std::cout << pieceChar << " ";
        }
        std::cout << std::endl;
    }
}