#pragma once
#include "../types/CastlingRights.hpp"
#include "../types/Color.hpp"
#include "../types/Move.hpp"
#include "../types/Square.hpp"
#include <iostream>
#include <list>
using namespace std;

list<Move> GetPieceMoves(SquarePosition position, Square board[8][8], Color turn)
{
    list<Move> moves         = list<Move>();
    Square     pieceAtSquare = board[position.file][position.rank];
    Move       newMove;
    if (pieceAtSquare.piece == PieceType::Empty_Piece || pieceAtSquare.color != turn)
    {
        return moves;
    }
    const int   moveLimit = pieceAtSquare.piece == PieceType::King || pieceAtSquare.piece == PieceType::Knight ? 1 : 8;
    const auto& moveTarget   = PieceMoveSets.at(pieceAtSquare.piece);
    for (const auto& moveDef : moveTarget)
    {
        int i = 1;
        for (i = 1; i < moveLimit + 1; i++)
        {
            int targetFile = position.file + (moveDef.file * i);
            int targetRank = position.rank + (moveDef.rank * i);
            if (targetFile < 0 || targetFile >= 8 || targetRank < 0 || targetRank >= 8)
            {
                continue;
            }
            const Square pieceAtTarget = board[targetFile][targetRank];
            const SquarePosition targetPosition = {targetFile, targetRank};
            if (pieceAtTarget.piece == PieceType::Empty_Piece)
            {
                // Empty Square
                newMove = {position, targetPosition, MoveType::move};
                moves.push_back(newMove);
            }
            else
            {
                if (pieceAtTarget.color != pieceAtSquare.color)
                {
                    // Opponent at target square
                    newMove = {position, targetPosition, MoveType::capture};
                    moves.push_back(newMove);
                }
                break;
            }
        }
    }
    return moves;
}

list<Move> GetPawnMovesForSquare(SquarePosition position, Square board[8][8], Color turn)
{
    list<Move> moves;
    return moves;
}

list<Move> GetLegalMovesForSquare(SquarePosition position, Square board[8][8], Color turn)
{
    list<Move> moves = GetPieceMoves(position, board, turn);
    return moves;
}

list<Move> GetLegalMoves(Square board[8][8], Color turn, CastlingRights castling_rights)
{
    list<Move> moves = GetLegalMovesForSquare( {0, 1}, board, Color::White);
    return moves;
}
