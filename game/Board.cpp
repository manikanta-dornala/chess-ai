
#include <iostream>
#include <list>
#include "../utils/utils.hpp"
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
using namespace std;

namespace Board
{
	void InitializeBoard(Square (&board)[8][8])
	{
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				board[row][col].piece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };
			}
		}

		for (int col = 0; col < 8; ++col)
		{
			board[1][col].piece = { .type = PIECETYPE_PAWN, .color = COLOR_WHITE };
			board[6][col].piece = { .type = PIECETYPE_PAWN, .color = COLOR_BLACK };
		}

		board[0][0].piece = { .type = PIECETYPE_ROOK, .color = COLOR_WHITE };
		board[0][7].piece = { .type = PIECETYPE_ROOK, .color = COLOR_WHITE };
		board[0][1].piece = { .type = PIECETYPE_KNIGHT, .color = COLOR_WHITE };
		board[0][6].piece = { .type = PIECETYPE_KNIGHT, .color = COLOR_WHITE };
		board[0][2].piece = { .type = PIECETYPE_BISHOP, .color = COLOR_WHITE };
		board[0][5].piece = { .type = PIECETYPE_BISHOP, .color = COLOR_WHITE };
		board[0][3].piece = { .type = PIECETYPE_QUEEN, .color = COLOR_WHITE };
		board[0][4].piece = { .type = PIECETYPE_KING, .color = COLOR_WHITE };

		board[7][0].piece = { .type = PIECETYPE_ROOK, .color = COLOR_BLACK };
		board[7][7].piece = { .type = PIECETYPE_ROOK, .color = COLOR_BLACK };
		board[7][1].piece = { .type = PIECETYPE_KNIGHT, .color = COLOR_BLACK };
		board[7][6].piece = { .type = PIECETYPE_KNIGHT, .color = COLOR_BLACK };
		board[7][2].piece = { .type = PIECETYPE_BISHOP, .color = COLOR_BLACK };
		board[7][5].piece = { .type = PIECETYPE_BISHOP, .color = COLOR_BLACK };
		board[7][3].piece = { .type = PIECETYPE_QUEEN, .color = COLOR_BLACK };
		board[7][4].piece = { .type = PIECETYPE_KING, .color = COLOR_BLACK };
	}

	void copyBoard(const Square (&original)[8][8], Square (&newBoard)[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Piece curr = original[i][j].piece;
				newBoard[i][j].piece = { curr.type, curr.color };
			}
		}
	}

	int numPiecesOnBoard(const Square (&board)[8][8])
	{
		int numPieces = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j].piece.type != PIECETYPE_NIL)
				{
					numPieces++;
				}
			}
		}
		return numPieces;
	}

	Piece GetPieceAtPosition(const Position& position, const Square (&board)[8][8])
	{
		if (position.IsValidPosition())
		{
			return board[position.rank][position.file].piece;
		}
		return { .type = PIECETYPE_NIL, .color = COLOR_NIL };
	}

	void printBoard(const Square (&board)[8][8])
	{
		for (int rank = 7; rank >= 0; --rank)
		{
			for (int file = 0; file < 8; ++file)
			{
				auto piece = GetPieceAtPosition({ .rank = rank, .file = file }, board);
				char pieceChar = piece.GetPieceCode();
				std::cout << pieceChar << " ";
			}
			std::cout << std::endl;
		}
	}

	float getScoreForBoard(const Square (&board)[8][8], const Color& turn)
	{
		return 0.0;
	}
} // namespace Board