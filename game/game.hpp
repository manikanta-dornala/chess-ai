#pragma once
#include "../utils/utils.hpp"
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
#include "../types/types.hpp"
#include <vector>
using namespace std;

// Moves
vector<Move> GetPieceMoves(const SquarePosition position, const Square board[8][8]);
vector<Move> GetPawnMovesForSquare(const SquarePosition position, const Square board[8][8]);
vector<Move> GetMovesForSquare(const SquarePosition position, const Square board[8][8]);
vector<Move> GetRegularMoves(const Color turn, const Square board[8][8]);
vector<Move> GetEnpassantMoves(const SquarePosition enapassant_target, const Square board[8][8]);
vector<Move> GetLegalMoves(const Color turn, const CastlingRights castling_rights, const SquarePosition enpassant_target, const Square board[8][8]);

// Board
void		 InitializeBoard(Square board[8][8]);
void		 copyBoard(const Square original[8][8], Square newBoard[8][8]);
int			 numPiecesOnBoard(const Square board[8][8]);
const Piece& GetPieceAtPosition(const Square board[8][8], SquarePosition position);
void		 printBoard(const Square board[8][8]);
float		 getScoreForBoard(const Square board[8][8], Color turn);
