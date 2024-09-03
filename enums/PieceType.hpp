#include <map>
using namespace std;

enum PieceType
{
	PIECETYPE_NIL = 0,
	PIECETYPE_PAWN,
	PIECETYPE_KNIGHT,
	PIECETYPE_BISHOP,
	PIECETYPE_ROOK,
	PIECETYPE_QUEEN,
	PIECETYPE_KING
};

const map<char, PieceType> PieceTypeMap = {
	{ 'p', PIECETYPE_PAWN },
	{ 'n', PIECETYPE_KNIGHT },
	{ 'b', PIECETYPE_BISHOP },
	{ 'r', PIECETYPE_ROOK },
	{ 'q', PIECETYPE_QUEEN },
	{ 'k', PIECETYPE_KING }
};