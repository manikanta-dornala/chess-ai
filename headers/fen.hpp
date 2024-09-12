#pragma once
#include <iostream>
#include <string>

#include "enums.hpp"
#include "structs.hpp"
using namespace std;
namespace FEN {

Color GetCurrentTurn(const string& fen);
CastlingRights GetCastlingRights(const string& fen);
Position GetEnPassantTarget(const string& fen);
BoardState GetBoardState(const string& fen);

} // namespace FEN
