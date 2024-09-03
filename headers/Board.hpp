#pragma once
#include <iostream>
#include <list>
#include "utils.hpp"
#include "enums.hpp"
#include "structs.hpp"
using namespace std;

namespace Board
{
    // Board
    void         InitializeBoard(Piece (&board)[8][8]);
    void         copyBoard(const Piece (&original)[8][8], Piece (&newBoard)[8][8]);
    int          numPiecesOnBoard(const Piece (&board)[8][8]);
    const Piece& GetPieceAtPosition(const Position& position, const Piece (&board)[8][8]);
    void         printBoard(const Piece (&board)[8][8]);
    float        getScoreForBoard(const Piece (&board)[8][8], const Color& turn);
} // namespace Board