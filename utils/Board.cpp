#pragma once
#include "../types/Color.cpp"
#include "../types/Square.cpp"
#include <iostream>
#include <string>

using namespace std;

void initializeBoard(Square board[8][8])
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            board[row][col].piece.type  = PieceType::Empty_Piece;
            board[row][col].piece.color = Color::Empty_Color;
        }
    }

    for (int col = 0; col < 8; ++col)
    {
        board[1][col].piece = {PieceType::Pawn, Color::White};
        board[6][col].piece = {PieceType::Pawn, Color::Black};
    }

    board[0][0].piece = {PieceType::Rook, Color::White};
    board[0][7].piece = {PieceType::Rook, Color::White};
    board[0][1].piece = {PieceType::Knight, Color::White};
    board[0][6].piece = {PieceType::Knight, Color::White};
    board[0][2].piece = {PieceType::Bishop, Color::White};
    board[0][5].piece = {PieceType::Bishop, Color::White};
    board[0][3].piece = {PieceType::Queen, Color::White};
    board[0][4].piece = {PieceType::King, Color::White};

    board[7][0].piece = {PieceType::Rook, Color::Black};
    board[7][7].piece = {PieceType::Rook, Color::Black};
    board[7][1].piece = {PieceType::Knight, Color::Black};
    board[7][6].piece = {PieceType::Knight, Color::Black};
    board[7][2].piece = {PieceType::Bishop, Color::Black};
    board[7][5].piece = {PieceType::Bishop, Color::Black};
    board[7][3].piece = {PieceType::Queen, Color::Black};
    board[7][4].piece = {PieceType::King, Color::Black};
}

void copyBoard(const Square original[8][8], Square newBoard[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Piece curr           = original[i][j].piece;
            newBoard[i][j].piece = {curr.type, curr.color};
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
            if (board[i][j].piece.type != PieceType::Empty_Piece)
            {
                numPieces++;
            }
        }
    }
    return numPieces;
}

void printBoard(const Square board[8][8])
{
    for (int rank = 7; rank >= 0; --rank)
    {
        for (int file = 0; file < 8; ++file)
        {
            char pieceChar = getPieceCode(board[rank][file].piece);
            std::cout << pieceChar << " ";
        }
        std::cout << std::endl;
    }
}

float getScoreForBoard(const Square board[8][8], Color turn)
{
    return 0.0;
}