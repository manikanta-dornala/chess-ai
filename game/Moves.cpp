#include "../headers/chessai.hpp"

using namespace std;

namespace Moves
{
	vector<Move> GetPieceMoves(const Position& position, const Piece (&board)[8][8])
	{
		auto  moves = vector<Move>();
		Piece piece = Board::GetPieceAtPosition(position, board);
		if (piece.type == PIECETYPE_NIL || piece.type == PIECETYPE_PAWN)
		{
			return moves;
		}
		int	 move_limit = piece.type == PIECETYPE_KING || piece.type == PIECETYPE_KNIGHT ? 1 : 8;
		auto move_destinations = GetPieceMoveDestinations(piece.type);

		for (auto destination : move_destinations)
		{
			int i = 1;
			for (i = 1; i < move_limit + 1; i++)
			{
				Position target_position = {
					.rank = position.rank + (destination.rank * i),
					.file = position.file + (destination.file * i)
				};

				if (target_position.IsValidPosition())
				{
					Piece piece_at_target = Board::GetPieceAtPosition(target_position, board);

					if (piece_at_target.type == PIECETYPE_NIL)
					{
						// Empty Piece
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
							// Opponent at target Piece
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
		}
		return moves;
	}

	vector<Move> GetPawnMovesForPiece(const Position& position, const Piece (&board)[8][8])
	{
		vector<Move> moves = {};
		auto		 piece = Board::GetPieceAtPosition(position, board);
		if (piece.type != PIECETYPE_PAWN)
			return moves;

		int destination = piece.color == COLOR_WHITE ? 1 : -1;

		// handle regular move on to a empty Piece
		Position forward_one = {
			.rank = position.rank + destination,
			.file = position.file,
		};
		if (forward_one.IsValidPosition() && Board::GetPieceAtPosition(forward_one, board).type == PIECETYPE_NIL)
		{
			moves.push_back({
				.curr = position,
				.target = forward_one,
				.type = MOVETYPE_MOVE,
			});

			// since it can make one move, handle double move if at initial rank
			int initial_rank = piece.color == COLOR_WHITE ? 1 : 6;
			if (position.rank == initial_rank)
			{
				Position forward_two = {
					.rank = position.rank + 2 * destination,
					.file = position.file,
				};
				if (forward_two.IsValidPosition() && Board::GetPieceAtPosition(forward_two, board).type == PIECETYPE_NIL)
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
		Position capture_positions[2] = {
			{ .rank = position.rank + destination, .file = position.file - 1 },
			{ .rank = position.rank + destination, .file = position.file + 1 }
		};
		for (Position capture_position : capture_positions)
		{
			if (!capture_position.IsValidPosition())
				continue;
			Piece piece_at_target = Board::GetPieceAtPosition(capture_position, board);
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

	vector<Move> GetMovesForPiece(const Position& position, const Piece (&board)[8][8])
	{
		vector<Move> pawn_moves = GetPawnMovesForPiece(position, board);
		vector<Move> piece_moves = GetPieceMoves(position, board);
		pawn_moves.insert(pawn_moves.end(), piece_moves.begin(), piece_moves.end());
		return pawn_moves;
	}

	vector<Move> GetRegularMoves(const Color& turn, const Piece (&board)[8][8])
	{
		vector<Move> moves = vector<Move>();
		for (int rank = 7; rank >= 0; --rank)
		{
			for (int file = 0; file < 8; ++file)
			{
				Position position = { .rank = rank, .file = file };
				Piece	 piece_at_position = Board::GetPieceAtPosition(position, board);
				if (piece_at_position.color == turn)
				{
					vector<Move> moves_at_Piece = GetMovesForPiece(position, board);
					cout << position.GetPieceCode() << " " << piece_at_position.GetPieceCode() << " " << moves_at_Piece.size() << "\n";
					moves.insert(
						moves.end(),
						moves_at_Piece.begin(),
						moves_at_Piece.end());
				}
			}
		}
		cout << "Regular Moves & Captures " << moves.size() << "\n";
		return moves;
	}

	vector<Move> GetEnpassantCaptures(const Position& enapassant_target, const Piece (&board)[8][8])
	{
		auto moves = vector<Move>();
		int	 capture_rank;
		if (enapassant_target.rank == 5)
			capture_rank = 4;
		else if (enapassant_target.rank == 2)
			capture_rank = 3;
		else
			return moves;

		auto capture_piece = Board::GetPieceAtPosition({ .rank = capture_rank, .file = enapassant_target.file }, board);

		Position positions[2] = {
			{ .rank = capture_rank, .file = enapassant_target.file + 1 },
			{ .rank = capture_rank, .file = enapassant_target.file - 1 },
		};
		for (auto position : positions)
		{
			if (position.IsValidPosition())
			{
				Piece piece = Board::GetPieceAtPosition(position, board);
				if (piece.color != capture_piece.color && piece.type != PIECETYPE_NIL)
				{
					moves.push_back({
						.curr = position,
						.target = enapassant_target,
						.type = MOVETYPE_ENPASSANT,
					});
					cout << position.GetPieceCode() << " " << piece.GetPieceCode() << " " << 1 << "\n";
				}
			}
		}
		cout << "Enpassant Captures " << moves.size() << "\n";
		return moves;
	}

	vector<Move> GetLegalMoves(const Color& turn, const CastlingRights& castling_rights, const Position& enpassant_target, const Piece (&board)[8][8])
	{
		auto moves = GetRegularMoves(turn, board);
		auto enpassant_captures = GetEnpassantCaptures(enpassant_target, board);
		moves.insert(moves.end(), enpassant_captures.begin(), enpassant_captures.end());
		return moves;
	}
} // namespace Moves