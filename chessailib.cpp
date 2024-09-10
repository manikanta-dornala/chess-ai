#include "chessai.hpp"

#include <emscripten/emscripten.h>

extern "C" {
EMSCRIPTEN_KEEPALIVE
char *GetBestMoveForFEN(char *fen)
{
    auto state = FEN::GetBoardState(fen);
    auto move = Board::GetBestMove(state);
    auto move_str = move.GetChars();
    char *char_array = new char[move_str.length() + 1];
    strcpy(char_array, move_str.c_str());
    return char_array;
}
}