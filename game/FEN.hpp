#pragma once
#include <iostream>
#include <string>
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
using namespace std;
namespace FEN
{
	void		   SetBoard(string& fen, Square board[8][8]);
	Color		   GetCurrentTurn(string& fen);
	CastlingRights GetCastlingRights(string& fen);
	Position	   GetEnPassantTarget(string& fen);

} // namespace FEN
