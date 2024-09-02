#pragma once
#include "types.hpp"
#include <iostream>
#include <string>
using namespace std;

string GetSquareCode(SquarePosition position)
{
	char result[2];
	result[0] = 'a' + position.file;
	result[1] = '1' + position.rank;
	return string(result);
}

bool IsValidPosition(SquarePosition position)
{
	return position.rank >= 0 && position.rank <= 7 && position.file >= 0 && position.file <= 7;
}
