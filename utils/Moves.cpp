#pragma once
#include "../types/CastlingRights.cpp"
#include "../types/Color.cpp"
#include "../types/Move.cpp"
#include "../types/Piece.cpp"
#include "../types/Square.cpp"
#include "Board.cpp"
#include <iostream>
#include <list>
using namespace std;

list<Move> GetPieceMoves(SquarePosition position, Square board[8][8])
{
    list<Move> moves         = list<Move>();
    Piece      pieceAtSquare = board[position.rank][position.file].piece;
    Move       newMove;
    if (pieceAtSquare.type == PieceType::Empty_Piece || pieceAtSquare.type == PieceType::Pawn)
    {
        return moves;
    }
    const int moveLimit =
        pieceAtSquare.type == PieceType::King || pieceAtSquare.type == PieceType::Knight ? 1 : 8;
    const auto& moveTarget = PieceMoveSets.at(pieceAtSquare.type);
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
            const Piece          pieceAtTarget  = board[targetRank][targetFile].piece;
            const SquarePosition targetPosition = {targetRank, targetFile};
            if (pieceAtTarget.type == PieceType::Empty_Piece)
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

list<Move> GetPawnMovesForSquare(SquarePosition position, Square board[8][8])
{
    list<Move> moves;
    return moves;
}

list<Move> GetMovesForSquare(SquarePosition position, Square board[8][8])
{
    list<Move> moves = GetPieceMoves(position, board);
    return moves;
}

list<Move> GetMoves(Square board[8][8], Color turn)
{
    list<Move> moves = list<Move>();
    for (int rank = 7; rank >= 0; --rank)
    {
        for (int file = 0; file < 8; ++file)
        {
            if (board[rank][file].piece.color == turn)
            {
                list<Move> movesAtSquare = GetMovesForSquare({rank, file}, board);
                // cout << getSquareCode({rank, file}) << " " <<
                // getPieceCode(board[rank][file].piece)
                //      << " " << movesAtSquare.size() << "\n";
                moves.insert(moves.end(), movesAtSquare.begin(), movesAtSquare.end());
            }
        }
    }
    return moves;
}

list<Move> GetLegalMoves(Square board[8][8], Color turn, CastlingRights castling_rights)
{
    list<Move> moves = GetMoves(board, turn);
    return moves;
}