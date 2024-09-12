#include "chessai.hpp"

#include <emscripten/bind.h> // Include Embind header
#include <emscripten/emscripten.h>

using namespace emscripten;

Move GetBestMoveForFEN(string fen)
{
    auto state = FEN::GetBoardState(fen);
    auto move = Board::GetBestMove(state);
    return move;
}

// Bind enums
EMSCRIPTEN_BINDINGS(my_module)
{
    // Bind the Color enum
    enum_<Color>("Color")
        .value("COLOR_NIL", COLOR_NIL)
        .value("COLOR_WHITE", COLOR_WHITE)
        .value("COLOR_BLACK", COLOR_BLACK);

    // Bind the MoveType enum
    enum_<MoveType>("MoveType")
        .value("MOVETYPE_NIL", MOVETYPE_NIL)
        .value("MOVETYPE_MOVE", MOVETYPE_MOVE)
        .value("MOVETYPE_DOUBLE_MOVE", MOVETYPE_DOUBLE_MOVE)
        .value("MOVETYPE_CAPTURE", MOVETYPE_CAPTURE)
        .value("MOVETYPE_ENPASSANT", MOVETYPE_ENPASSANT)
        .value("MOVETYPE_PROMOTE", MOVETYPE_PROMOTE)
        .value("MOVETYPE_CASTLING", MOVETYPE_CASTLING);

    // Bind the PieceType enum
    enum_<PieceType>("PieceType")
        .value("PIECETYPE_NIL", PIECETYPE_NIL)
        .value("PIECETYPE_PAWN", PIECETYPE_PAWN)
        .value("PIECETYPE_KNIGHT", PIECETYPE_KNIGHT)
        .value("PIECETYPE_BISHOP", PIECETYPE_BISHOP)
        .value("PIECETYPE_ROOK", PIECETYPE_ROOK)
        .value("PIECETYPE_QUEEN", PIECETYPE_QUEEN)
        .value("PIECETYPE_KING", PIECETYPE_KING);

    // Bind the CastlingRights struct
    value_object<CastlingRights>("CastlingRights")
        .field("white_king_side", &CastlingRights::white_king_side)
        .field("white_queen_side", &CastlingRights::white_queen_side)
        .field("black_king_side", &CastlingRights::black_king_side)
        .field("black_queen_side", &CastlingRights::black_queen_side);

    // Bind the Position class
    value_object<Position>("Position")
        .field("rank", &Position::rank)
        .field("file", &Position::file);

    // Bind the Piece class
    value_object<Piece>("Piece")
        .field("type", &Piece::type)
        .field("color", &Piece::color);

    // Bind the Move struct
    value_object<Move>("Move")
        .field("curr", &Move::curr)
        .field("target", &Move::target)
        .field("piece", &Move::piece)
        .field("type", &Move::type);

    // Bind the BoardState struct
    value_object<BoardState>("BoardState")
        .field("board", &BoardState::board)
        .field("castling_rights", &BoardState::castling_rights)
        .field("enpassant_target", &BoardState::enpassant_target)
        .field("turn", &BoardState::turn);

    // Bind the function to get the best move
    emscripten::function("GetBestMoveForFEN", &GetBestMoveForFEN);
}