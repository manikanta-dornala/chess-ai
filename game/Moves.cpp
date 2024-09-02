#pragma once
#include "../types/types.hpp"
#include "Board.cpp"
#include <iostream>
#include <list>
using namespace std;

vector<Move> GetPieceMoves(const SquarePosition position, const Square board[8][8])
{
	auto  moves = vector<Move>();
	Piece piece = GetPieceAtPosition(board, position);
	if (piece.type == PIECETYPE_NIL || piece.type == PIECETYPE_PAWN)
	{
		return moves;
	}
	const int  move_limit = piece.type == PIECETYPE_KING || piece.type == PIECETYPE_KNIGHT ? 1 : 8;
	const auto move_set = GetPieceMoveSets(piece.type);
	for (const auto unit_move : move_set)
	{
		int i = 1;
		for (i = 1; i < move_limit + 1; i++)
		{
			const SquarePosition target_position = {
				.rank = position.rank + (unit_move.rank * i),
				.file = position.file + (unit_move.file * i)
			};

			if (!IsValidPosition(target_position))
				continue;

			const Piece piece_at_target = GetPieceAtPosition(board, target_position);

			if (piece_at_target.type == PIECETYPE_NIL)
			{
				// Empty Square
				moves.push_back({
					.curr = position,
					.target = target_position,
					.type = MOVETYPE_MOVE,
				});
			}
			else
			{
				if (piece_at_target.color != piece.color)
				{
					// Opponent at target square
					moves.push_back({
						.curr = position,
						.target = target_position,
						.type = MOVETYPE_CAPTURE,
					});
				}
				break;
			}
		}
	}
	return moves;
}

vector<Move> GetPawnMovesForSquare(const SquarePosition position, const Square board[8][8])
{
	vector<Move> moves = {};
	const auto	 piece = GetPieceAtPosition(board, position);
	if (piece.type != PIECETYPE_PAWN)
		return moves;

	const int unit_move = piece.color == COLOR_WHITE ? 1 : -1;

	// handle regular move on to a empty square
	const SquarePosition forward_one = {
		.rank = position.rank + unit_move,
		.file = position.file,
	};
	if (IsValidPosition(forward_one) && GetPieceAtPosition(board, forward_one).type == PIECETYPE_NIL)
	{
		moves.push_back({
			.curr = position,
			.target = forward_one,
			.type = MOVETYPE_MOVE,
		});

		// since it can make one move, handle double move if at initial rank
		const int initial_rank = piece.color == COLOR_WHITE ? 1 : 6;
		if (position.rank == initial_rank)
		{
			const SquarePosition forward_two = {
				.rank = position.rank + 2 * unit_move,
				.file = position.file,
			};
			if (IsValidPosition(forward_two) && GetPieceAtPosition(board, forward_two).type == PIECETYPE_NIL)
			{
				moves.push_back({
					.curr = position,
					.target = forward_two,
					.type = MOVETYPE_MOVE,
				});
			}
		}
	}

	// handle capture
	const SquarePosition capture_positions[2] = {
		{ .rank = position.rank + unit_move, .file = position.file - 1 },
		{ .rank = position.rank + unit_move, .file = position.file + 1 }
	};
	for (const SquarePosition capture_position : capture_positions)
	{
		if (!IsValidPosition(capture_position))
			continue;
		const Piece piece_at_target = GetPieceAtPosition(board, capture_position);
		if (piece_at_target.type != PIECETYPE_NIL && piece.color != piece_at_target.color)
		{
			moves.push_back({
				.curr = position,
				.target = capture_position,
				.type = MOVETYPE_CAPTURE,
			});
		}
	}

	return moves;
}

vector<Move> GetMovesForSquare(const SquarePosition position, const Square board[8][8])
{
	vector<Move> pawn_moves = GetPawnMovesForSquare(position, board);
	vector<Move> piece_moves = GetPieceMoves(position, board);
	pawn_moves.insert(pawn_moves.end(), piece_moves.begin(), piece_moves.end());
	return pawn_moves;
}

vector<Move> GetRegularMoves(
	const Color turn, const Square board[8][8])
{
	vector<Move> moves = vector<Move>();
	for (int rank = 7; rank >= 0; --rank)
	{
		for (int file = 0; file < 8; ++file)
		{
			if (GetPieceAtPosition(board, { .rank = rank, .file = file }).color == turn)
			{
				vector<Move> moves_at_square = GetMovesForSquare({ .rank = rank, .file = file }, board);
				// cout << GetSquareCode({rank, file}) << " " <<
				// GetPieceCode(board[rank][file].piece)
				//      << " " << moves_at_square.size() << "\n";
				moves.insert(
					moves.end(),
					moves_at_square.begin(),
					moves_at_square.end());
			}
		}
	}
	return moves;
}

vector<Move> GetEnpassantMoves(
	const SquarePosition enapassant_target,
	const Square		 board[8][8])
{
	auto moves = vector<Move>();
	int	 capture_rank;
	if (enapassant_target.rank == 5)
		capture_rank = 4;
	else if (enapassant_target.rank == 2)
		capture_rank = 3;
	else
		return moves;

	auto capture_piece = GetPieceAtPosition(board, { .rank = capture_rank, .file = enapassant_target.file });

	SquarePosition positions[2] = {
		{ .rank = capture_rank, .file = enapassant_target.file + 1 },
		{ .rank = capture_rank, .file = enapassant_target.file - 1 },
	};
	for (auto position : positions)
	{
		if (IsValidPosition(position))
		{
			Piece piece = GetPieceAtPosition(board, position);
			if (piece.color != capture_piece.color && piece.type != PIECETYPE_NIL)
			{
				moves.push_back({
					.curr = position,
					.target = enapassant_target,
					.type = MOVETYPE_ENPASSANT,
				});
			}
		}
	}
	cout << moves.size() << "\n";
	return moves;
}

vector<Move> GetLegalMoves(
	const Color			 turn,
	const CastlingRights castling_rights,
	const SquarePosition enpassant_target,
	const Square		 board[8][8])
{
	auto moves = GetRegularMoves(turn, board);
	auto enpassant_moves = GetEnpassantMoves(enpassant_target, board);
	return moves;
}