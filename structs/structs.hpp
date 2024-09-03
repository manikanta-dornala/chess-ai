#pragma once

struct CastlingRights
{
	bool white_king_side;
	bool white_queen_side;
	bool black_king_side;
	bool black_queen_side;
};

class Position
{
	public:
	int rank;

	public:
	int file;

	public:
	bool IsValidPosition();

	public:
	string GetSquareCode();
};

struct Move
{
	Position curr;
	Position target;
	MoveType type;
};

vector<Position>& GetPieceMoveSet(PieceType piece_type);

class Piece
{
	public:
	PieceType type;
	Color	  color;
	char	  GetPieceCode();
};

// expr Piece DefaultPiece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };

struct Square
{
	Piece piece;
};
