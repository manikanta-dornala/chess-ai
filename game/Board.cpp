#include "../headers/chessai.hpp"
using namespace std;

namespace Board
{
	const Piece DefaultPiece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };

	void		InitializeBoard(Piece (&board)[8][8])
	{
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				board[row][col] = DefaultPiece;
			}
		}

		for (int col = 0; col < 8; ++col)
		{
			board[1][col] = { .type = PIECETYPE_PAWN, .color = COLOR_WHITE };
			board[6][col] = { .type = PIECETYPE_PAWN, .color = COLOR_BLACK };
		}

		board[0][0] = { .type = PIECETYPE_ROOK, .color = COLOR_WHITE };
		board[0][7] = { .type = PIECETYPE_ROOK, .color = COLOR_WHITE };
		board[0][1] = { .type = PIECETYPE_KNIGHT, .color = COLOR_WHITE };
		board[0][6] = { .type = PIECETYPE_KNIGHT, .color = COLOR_WHITE };
		board[0][2] = { .type = PIECETYPE_BISHOP, .color = COLOR_WHITE };
		board[0][5] = { .type = PIECETYPE_BISHOP, .color = COLOR_WHITE };
		board[0][3] = { .type = PIECETYPE_QUEEN, .color = COLOR_WHITE };
		board[0][4] = { .type = PIECETYPE_KING, .color = COLOR_WHITE };

		board[7][0] = { .type = PIECETYPE_ROOK, .color = COLOR_BLACK };
		board[7][7] = { .type = PIECETYPE_ROOK, .color = COLOR_BLACK };
		board[7][1] = { .type = PIECETYPE_KNIGHT, .color = COLOR_BLACK };
		board[7][6] = { .type = PIECETYPE_KNIGHT, .color = COLOR_BLACK };
		board[7][2] = { .type = PIECETYPE_BISHOP, .color = COLOR_BLACK };
		board[7][5] = { .type = PIECETYPE_BISHOP, .color = COLOR_BLACK };
		board[7][3] = { .type = PIECETYPE_QUEEN, .color = COLOR_BLACK };
		board[7][4] = { .type = PIECETYPE_KING, .color = COLOR_BLACK };
	}

	void copyBoard(const Piece (&original)[8][8], Piece (&newBoard)[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Piece curr = original[i][j];
				newBoard[i][j] = { curr.type, curr.color };
			}
		}
	}

	int numPiecesOnBoard(const Piece (&board)[8][8])
	{
		int numPieces = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j].type != PIECETYPE_NIL)
				{
					numPieces++;
				}
			}
		}
		return numPieces;
	}

	const Piece& GetPieceAtPosition(const Position& position, const Piece (&board)[8][8])
	{
		if (position.IsValidPosition())
		{
			return board[position.rank][position.file];
		}
		return DefaultPiece;
	}

	void printBoard(const Piece (&board)[8][8])
	{
		for (int rank = 7; rank >= 0; --rank)
		{
			for (int file = 0; file < 8; ++file)
			{
				auto piece = GetPieceAtPosition({ .rank = rank, .file = file }, board);
				char   pieceChar = piece.GetPieceCode();
				std::cout << pieceChar << " ";
			}
			std::cout << std::endl;
		}
	}

	float getScoreForBoard(const Piece (&board)[8][8], const Color& turn)
	{
		return 0.0;
	}
} // namespace Board