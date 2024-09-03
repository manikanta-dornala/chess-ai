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
	bool IsValidPosition() const;

	public:
	string GetSquareCode() const;
};

struct Move
{
	Position curr;
	Position target;
	MoveType type;
};

const vector<Position>& GetPieceMoveSet(PieceType piece_type);

class Piece
{
	public:
	PieceType type = PIECETYPE_NIL;
	Color	  color = COLOR_NIL;
	char	  GetPieceCode();
};

// constexpr Piece DefaultPiece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };

struct Square
{
	Piece piece;
};
