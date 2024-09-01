#pragma once
#include <iostream>
#include <list>
#include "types/Square.hpp"
#include "types/Move.hpp"
#include "types/Color.hpp"
#include "types/CastlingRights.hpp"
using namespace std;

list<Move> GetPieceMoves(int file, int rank, Square board[8][8], Color turn)
{
    list<Move> moves = {};
    Square pieceAtSquare = board[file][rank];
    Move newMove;
    if (pieceAtSquare.piece == no_piece || pieceAtSquare.color != turn)
    {
        return moves;
    }
    cout << pieceAtSquare.piece << pieceAtSquare.color << "\n";
    const int moveLimit = pieceAtSquare.piece == king || pieceAtSquare.piece == knight ? 1 : 8;
    const list<MoveSet> moveSet = PieceMoveSets.at(pieceAtSquare.piece);
    for (const auto &moveDef : moveSet)
    {
        int i = 1;
        for (i = 1; i < moveLimit + 1; i++)
        {
            int targetFile = file + (moveDef.file * i);
            int targetRank = rank + (moveDef.rank * i);
            // cout << i << "|" << moveDef.file << " " << moveDef.rank  << "\n";
            if (targetFile < 0 || targetFile >= 8 || targetRank < 0 || targetRank >= 8)
            {
                // cout << moveDef.file << " " << moveDef.rank << "|" << file << " " << rank  << "|" << targetFile << " " << targetRank <<" "<<i<< " is outside\n";
                continue;
            }

            const Square pieceAtTarget = board[targetFile][targetRank];
            if (pieceAtTarget.piece == no_piece)
            {
                // Empty Square
                newMove = {file,
                           rank,
                           targetFile,
                           targetRank,
                           MoveType::move};
                moves.push_back(newMove);
                // cout << moveDef.file << " " << moveDef.rank << "|" << file << " " << rank  << "|" << targetFile << " " << targetRank << " "<<i <<" regular\n";
            }
            else if (pieceAtTarget.piece != no_piece && pieceAtTarget.color != no_color && pieceAtTarget.color != pieceAtSquare.color)
            {
                // Opponent at target square
                newMove = {file,
                           rank,
                           targetFile,
                           targetRank,
                           MoveType::capture};
                moves.push_back(newMove);
                // cout << moveDef.file << " " << moveDef.rank << "|" << file << " " << rank  << "|" << targetFile << " " << targetRank << " "<<i<<" capture\n";
                break;
            }
            else
            {

                // cout << moveDef.file << " " << moveDef.rank << "|" << file << " " << rank  << "|" << targetFile << " " << targetRank << " "<<i<<" my piece\n";
                break;
            }
        }
    }
    cout << moves.size() << "\n";
    return moves;
}

list<Move> GetLegalMovesForSquare(int file, int rank, Square board[8][8], Color turn)
{
    list<Move> moves = GetPieceMoves(file, rank, board, turn);
    return moves;
}

list<Move> GetLegalMoves(Square board[8][8], Color turn, CastlingRights castling_rights)
{
    list<Move> moves = GetLegalMovesForSquare(0, 4, board, white);
    return moves;
}
