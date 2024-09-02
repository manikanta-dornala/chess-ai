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
    const vector<SquarePosition> moveTarget = PieceMoveSets.at(pieceAtSquare.type);
    for (const SquarePosition moveDef : moveTarget)
    {
        int i = 1;
        for (i = 1; i < moveLimit + 1; i++)
        {
            const SquarePosition targetPosition = {
                position.rank + (moveDef.rank * i), position.file + (moveDef.file * i)
            };

            if (!isPositionValid(targetPosition))
                continue;

            const Piece pieceAtTarget = board[targetPosition.rank][targetPosition.file].piece;

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
    list<Move>  moves           = {};
    const Piece pieceAtPosition = board[position.rank][position.file].piece;
    if (pieceAtPosition.type != Pawn)
        return moves;

    const int moveDir = pieceAtPosition.color == White ? 1 : -1;

    // handle regular move on to a empty square
    const SquarePosition forwardOne = {position.rank + moveDir, position.file};
    if (isPositionValid(forwardOne) &&
        board[forwardOne.rank][forwardOne.file].piece.type == PieceType::Empty_Piece)
    {
        moves.push_back({position, forwardOne, MoveType::move});

        // since it can make one move, handle double move if at initial rank
        const int initialRank = pieceAtPosition.color == White ? 1 : 6;
        if (position.rank == initialRank)
        {
            const SquarePosition forwardTwo = {position.rank + 2 * moveDir, position.file};
            if (isPositionValid(forwardTwo) &&
                board[forwardTwo.rank][forwardTwo.file].piece.type == PieceType::Empty_Piece)
            {
                moves.push_back({position, forwardTwo, MoveType::move});
            }
        }
    }

    // handle capture
    const SquarePosition capturePositions[2] = {
        {position.rank + moveDir, position.file - 1},
        {position.rank + moveDir, position.file + 1}
    };
    for (const SquarePosition capturePosition : capturePositions)
    {
        if (!isPositionValid(capturePosition))
            continue;
        const Piece pieceAtTarget = board[capturePosition.rank][capturePosition.file].piece;
        if (pieceAtTarget.type != PieceType::Empty_Piece &&
            pieceAtPosition.color != pieceAtTarget.color)
        {
            moves.push_back({position, capturePosition, MoveType::capture});
        }
    }

    return moves;
}

list<Move> GetMovesForSquare(SquarePosition position, Square board[8][8])
{
    list<Move> pawnMoves  = GetPawnMovesForSquare(position, board);
    list<Move> pieceMoves = GetPieceMoves(position, board);
    pawnMoves.insert(pawnMoves.end(), pieceMoves.begin(), pieceMoves.end());
    return pawnMoves;
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