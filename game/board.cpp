#include "../chessai.hpp"
using namespace std;

namespace Board
{
    const Piece DefaultPiece = {.type = PIECETYPE_NIL, .color = COLOR_NIL};

    void InitializeBoard(BoardArray &board)
    {

        for (int col = 0; col < 8; ++col)
        {
            board[RANK_2][col] = {.type = PIECETYPE_PAWN, .color = COLOR_WHITE};
            board[RANK_7][col] = {.type = PIECETYPE_PAWN, .color = COLOR_BLACK};
        }

        board[RANK_1][FILE_a] = {PIECETYPE_ROOK, COLOR_WHITE};
        board[RANK_1][FILE_b] = {PIECETYPE_KNIGHT, COLOR_WHITE};
        board[RANK_1][FILE_c] = {PIECETYPE_BISHOP, COLOR_WHITE};
        board[RANK_1][FILE_d] = {PIECETYPE_QUEEN, COLOR_WHITE};
        board[RANK_1][FILE_e] = {PIECETYPE_KING, COLOR_WHITE};
        board[RANK_1][FILE_f] = {PIECETYPE_BISHOP, COLOR_WHITE};
        board[RANK_1][FILE_g] = {PIECETYPE_KNIGHT, COLOR_WHITE};
        board[RANK_1][FILE_h] = {PIECETYPE_ROOK, COLOR_WHITE};

        board[RANK_8][FILE_a] = {PIECETYPE_ROOK, COLOR_BLACK};
        board[RANK_8][FILE_b] = {PIECETYPE_KNIGHT, COLOR_BLACK};
        board[RANK_8][FILE_c] = {PIECETYPE_BISHOP, COLOR_BLACK};
        board[RANK_8][FILE_d] = {PIECETYPE_QUEEN, COLOR_BLACK};
        board[RANK_8][FILE_e] = {PIECETYPE_KING, COLOR_BLACK};
        board[RANK_8][FILE_f] = {PIECETYPE_BISHOP, COLOR_BLACK};
        board[RANK_8][FILE_g] = {PIECETYPE_KNIGHT, COLOR_BLACK};
        board[RANK_8][FILE_h] = {PIECETYPE_ROOK, COLOR_BLACK};
    }

    void copyBoard(const BoardArray &original, BoardArray &newBoard)
    {
        for (int rank = 0; rank < 8; rank++)
        {
            for (int file = 0; file < 8; file++)
            {
                Piece curr = original[rank][file];
                newBoard[rank][file] = {curr.type, curr.color};
            }
        }
    }

    int numPiecesOnBoard(const BoardArray &board)
    {
        int numPieces = 0;
        for (int rank = 0; rank < 8; rank++)
        {
            for (int file = 0; file < 8; file++)
            {
                if (board[rank][file].type != PIECETYPE_NIL)
                {
                    numPieces++;
                }
            }
        }
        return numPieces;
    }

    const Piece GetPieceAtPosition(const Position position,
                                   const BoardArray &board)
    {
        if (position.IsValidPosition())
        {
            return board[position.rank][position.file];
        }
        return DefaultPiece;
    }

    void printBoard(const BoardArray &board)
    {
        for (int rank = 7; rank >= 0; --rank)
        {
            for (int file = 0; file < 8; ++file)
            {
                auto piece =
                    GetPieceAtPosition({.rank = rank, .file = file}, board);
                char pieceChar = piece.GetPieceCode();
                std::cout << pieceChar << " ";
            }
            std::cout << std::endl;
        }
    }

    Position GetKingPosition(const Color turn, const BoardArray &board)
    {
        for (int rank = 7; rank >= 0; --rank)
        {
            for (int file = 0; file < 8; ++file)
            {
                Position position = {.rank = rank, .file = file};
                auto piece = GetPieceAtPosition(position, board);
                if (piece.color == turn && piece.type == PIECETYPE_KING)
                {
                    return position;
                }
            }
        }
        return {-1, -1};
    }

    bool IsKingInCheck(const Color turn, const BoardArray &board)
    {
        auto king_position = GetKingPosition(turn, board);
        return IsKingInCheckAt(turn, king_position, board);
    }

    bool IsKingInCheckAt(const Color turn,
                         const Position king_position,
                         const BoardArray &board)
    {
        for (int rank = 7; rank >= 0; --rank)
        {
            for (int file = 0; file < 8; ++file)
            {
                Position position = {.rank = rank, .file = file};
                auto piece = GetPieceAtPosition(position, board);
                if (piece.type != PIECETYPE_NIL && piece.color != turn)
                {
                    const auto moves =
                        Board::GetMovesForPieceAt(position, board);
                    for (auto move : moves)
                    {
                        if (move.target.rank == king_position.rank
                            && move.target.file == king_position.file)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool IsPositionEmpty(const Position position, const BoardArray &board)
    {
        return GetPieceAtPosition(position, board).type == PIECETYPE_NIL;
    }

    BoardState NewBoardAfterMove(const Move move, const BoardState state)
    {
        BoardArray boardCopy;
        Board::copyBoard(state.board, boardCopy);
        auto castling_rights = state.castling_rights;
        auto enpassant_target = state.enpassant_target;
        switch (move.type)
        {
            case MOVETYPE_MOVE:
                boardCopy[move.target.rank][move.target.file] = move.piece;
                boardCopy[move.curr.rank][move.curr.file] = Piece();
                if (move.piece.type == PIECETYPE_KING)
                {
                    if (move.piece.color == COLOR_WHITE)
                    {
                        castling_rights.white_king_side = false;
                        castling_rights.white_queen_side = false;
                    }
                    if (move.piece.color == COLOR_BLACK)
                    {
                        castling_rights.black_king_side = false;
                        castling_rights.black_queen_side = false;
                    }
                }
                enpassant_target = Position();
                break;
            case MOVETYPE_DOUBLE_MOVE:
                boardCopy[move.target.rank][move.target.file] = move.piece;
                boardCopy[move.curr.rank][move.curr.file] = Piece();
                enpassant_target = move.target;
                break;
            case MOVETYPE_CAPTURE:
                boardCopy[move.target.rank][move.target.file] = move.piece;
                boardCopy[move.curr.rank][move.curr.file] = Piece();
                if (move.piece.type == PIECETYPE_KING)
                {
                    if (move.piece.color == COLOR_WHITE)
                    {
                        castling_rights.white_king_side = false;
                        castling_rights.white_queen_side = false;
                    }
                    if (move.piece.color == COLOR_BLACK)
                    {
                        castling_rights.black_king_side = false;
                        castling_rights.black_queen_side = false;
                    }
                }
                enpassant_target = Position();
                break;
            case MOVETYPE_ENPASSANT: {
                boardCopy[move.target.rank][move.target.file] = move.piece;
                boardCopy[move.curr.rank][move.curr.file] = Piece();
                Position enpassant_capture = {
                    .rank = move.piece.color == COLOR_WHITE ? RANK_5 : RANK_4,
                    .file = move.target.file};
                boardCopy[enpassant_capture.rank][enpassant_capture.file] =
                    Piece();
                enpassant_target = Position();
                break;
            }
            case MOVETYPE_CASTLING: {
                boardCopy[move.target.rank][move.target.file] = move.piece;
                boardCopy[move.curr.rank][move.curr.file] = Piece();
                Position rook_curr_position = {
                    .rank = move.target.rank,
                    .file = move.target.file == FILE_c ? FILE_a : FILE_h};
                Position rook_final_position = {
                    .rank = move.target.rank,
                    .file = move.target.file == FILE_c ? FILE_d : FILE_f};
                boardCopy[rook_final_position.rank][rook_final_position.file] =
                    {.type = PIECETYPE_ROOK, .color = move.piece.color};
                boardCopy[rook_curr_position.rank][rook_curr_position.file] =
                    Piece();
                if (move.piece.color == COLOR_WHITE)
                {
                    castling_rights.white_king_side = false;
                    castling_rights.white_queen_side = false;
                }
                if (move.piece.color == COLOR_BLACK)
                {
                    castling_rights.black_king_side = false;
                    castling_rights.black_queen_side = false;
                }
                enpassant_target = Position();
                break;
            }
            default:
                break;
        }
        return {.board = boardCopy,
                .turn = state.turn == COLOR_WHITE ? COLOR_BLACK : COLOR_WHITE,
                .castling_rights = state.castling_rights,
                .enpassant_target = state.enpassant_target};
    }

} // namespace Board