#pragma once
#include <vector>
#include "../utils/utils.hpp"
#include "../enums/enums.hpp"
#include "../structs/structs.hpp"
#include "../types/types.hpp"
using namespace std;

template <typename T>
vector<T> Concatenate(const vector<T>& vec1, const vector<T>& vec2)
{
	vector<T> result = vec1;
	result.insert(result.end(), vec2.begin(), vec2.end());
	return result;
}

// fen
void		   SetBoardFromFEN(const string& fen, Square board[8][8]);
Color		   GetCurrentTurnFromFEN(const string& fen);
CastlingRights GetCastlingRightsFromFEN(const string& fen);
SquarePosition GetEnPassantTargetFromFEN(const string& fen);