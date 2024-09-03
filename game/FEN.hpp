#pragma once
#include <iostream>
#include <string>
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
using namespace std;
namespace FEN
{
	void		   SetBoard(const string& fen, Square (&board)[8][8]);
	Color		   GetCurrentTurn(const string& fen);
	CastlingRights GetCastlingRights(const string& fen);
	Position	   GetEnPassantTarget(const string& fen);

} // namespace FEN
