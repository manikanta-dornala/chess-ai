#include "../headers/chessai.hpp"
using namespace std;

namespace Board
{
    const Piece DefaultPiece = { .type = PIECETYPE_NIL, .color = COLOR_NIL };

    void InitializeBoard(BoardArray& board)
    {
        for (int row = 0; row < 8; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                board[row][col] = DefaultPiece;
            }
        }

        for (int col = 0; col < 8; ++col)
        {
            board[1][col] = { .type = PIECETYPE_PAWN, .color = COLOR_WHITE };
            board[6][col] = { .type = PIECETYPE_PAWN, .color = COLOR_BLACK };
        }

        board[0][0] = { .type = PIECETYPE_ROOK, .color = COLOR_WHITE };
        board[0][7] = { .type = PIECETYPE_ROOK, .color = COLOR_WHITE };
        board[0][1] = { .type = PIECETYPE_KNIGHT, .color = COLOR_WHITE };
        board[0][6] = { .type = PIECETYPE_KNIGHT, .color = COLOR_WHITE };
        board[0][2] = { .type = PIECETYPE_BISHOP, .color = COLOR_WHITE };
        board[0][5] = { .type = PIECETYPE_BISHOP, .color = COLOR_WHITE };
        board[0][3] = { .type = PIECETYPE_QUEEN, .color = COLOR_WHITE };
        board[0][4] = { .type = PIECETYPE_KING, .color = COLOR_WHITE };

        board[7][0] = { .type = PIECETYPE_ROOK, .color = COLOR_BLACK };
        board[7][7] = { .type = PIECETYPE_ROOK, .color = COLOR_BLACK };
        board[7][1] = { .type = PIECETYPE_KNIGHT, .color = COLOR_BLACK };
        board[7][6] = { .type = PIECETYPE_KNIGHT, .color = COLOR_BLACK };
        board[7][2] = { .type = PIECETYPE_BISHOP, .color = COLOR_BLACK };
        board[7][5] = { .type = PIECETYPE_BISHOP, .color = COLOR_BLACK };
        board[7][3] = { .type = PIECETYPE_QUEEN, .color = COLOR_BLACK };
        board[7][4] = { .type = PIECETYPE_KING, .color = COLOR_BLACK };
    }

    void copyBoard(const BoardArray& original, BoardArray& newBoard)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Piece curr = original[i][j];
                newBoard[i][j] = { curr.type, curr.color };
            }
        }
    }

    int numPiecesOnBoard(const BoardArray& board)
    {
        int numPieces = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j].type != PIECETYPE_NIL)
                {
                    numPieces++;
                }
            }
        }
        return numPieces;
    }

    const Piece& GetPieceAtPosition(const Position& position, const BoardArray& board)
    {
        if (position.IsValidPosition())
        {
            return board[position.rank][position.file];
        }
        return DefaultPiece;
    }

    void printBoard(const BoardArray& board)
    {
        for (int rank = 7; rank >= 0; --rank)
        {
            for (int file = 0; file < 8; ++file)
            {
                auto piece = GetPieceAtPosition({ .rank = rank, .file = file }, board);
                char pieceChar = piece.GetPieceCode();
                std::cout << pieceChar << " ";
            }
            std::cout << std::endl;
        }
    }

    Position GetKingPosition(const Color turn, const BoardArray& board)
    {
        for (int rank = 7; rank >= 0; --rank)
        {
            for (int file = 0; file < 8; ++file)
            {
                Position position = { .rank = rank, .file = file };
                auto     piece = GetPieceAtPosition(position, board);
                if (piece.color == turn && piece.type == PIECETYPE_KING)
                {
                    return position;
                }
            }
        }
        return { -1, -1 };
    }

    bool IsKingInCheck(const Color turn, const BoardArray& board)
    {
        auto king_position = GetKingPosition(turn, board);
        return IsKingInCheckAt(turn, king_position, board);
    }

    bool IsKingInCheckAt(const Color turn, const Position& king_position, const BoardArray& board)
    {
        for (int rank = 7; rank >= 0; --rank)
        {
            for (int file = 0; file < 8; ++file)
            {
                Position position = { .rank = rank, .file = file };
                auto     piece = GetPieceAtPosition(position, board);
                if (piece.type != PIECETYPE_NIL && piece.color != turn)
                {
                    const auto moves = Moves::GetMovesForPieceAt(position, board);
                    for (auto move : moves)
                    {
                        if (move.target.rank == king_position.rank && move.target.file == king_position.file)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool IsPositionEmpty(const Position& position, const BoardArray& board)
    {
        return GetPieceAtPosition(position, board).type == PIECETYPE_NIL;
    }

    BoardArray NewBoardAfterMove(Move move, Color turn, const BoardArray& board)
    {
        BoardArray boardCopy;
        Board::copyBoard(board, boardCopy);
        auto        piece = Board::GetPieceAtPosition(move.curr, boardCopy);
        const Piece nil_piece = { PIECETYPE_NIL, COLOR_NIL };
        switch (move.type)
        {
            case MOVETYPE_MOVE:
            case MOVETYPE_DOUBLE_MOVE:
            case MOVETYPE_CAPTURE:
                boardCopy[move.target.rank][move.target.file] = piece;
                boardCopy[move.curr.rank][move.curr.file] = nil_piece;
                break;
            case MOVETYPE_ENPASSANT:
            {
                boardCopy[move.target.rank][move.target.file] = piece;
                boardCopy[move.curr.rank][move.curr.file] = nil_piece;
                Position enpassant_capture = {
                    .rank = piece.color == COLOR_WHITE ? 4 : 3,
                    .file = move.target.file
                };
                boardCopy[enpassant_capture.rank][enpassant_capture.file] = nil_piece;
            }
            case MOVETYPE_CASTLING:
            {
                boardCopy[move.target.rank][move.target.file] = piece;
                boardCopy[move.curr.rank][move.curr.file] = nil_piece;
                Position rook_curr_position = {
                    .rank = move.target.rank,
                    .file = move.target.file == 2 ? 0 : 7
                };
                Position rook_final_position = {
                    .rank = move.target.rank,
                    .file = move.target.file == 2 ? 3 : 5
                };
                boardCopy[rook_final_position.rank][rook_final_position.file] = { .type = PIECETYPE_ROOK, .color = piece.color };
                boardCopy[rook_curr_position.rank][rook_curr_position.file] = nil_piece;
                // king_position = move.target;
            }
            default:
                break;
        }
        return boardCopy;
    }

} // namespace Board