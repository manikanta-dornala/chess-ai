#pragma once
#include "Piece.cpp"
#include <iostream>
#include <string>
using namespace std;

struct Square
{
	Piece piece;
};

struct SquarePosition
{
	int rank;
	int file;
};

char   files[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
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
