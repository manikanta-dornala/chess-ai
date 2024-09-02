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

const char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
string     getSquareCode(SquarePosition position)
{
    char result[2];
    result[0] = 'a' + position.file;
    result[1] = '1' + position.rank;
    cout << result << "\n";
    return string(result);
}