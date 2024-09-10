#include "../chessai.hpp"

using namespace std;

namespace Board
{

    Moves GetPawnMovesForPieceAt(const Position position,
                                 const BoardArray &board)
    {
        Moves moves;
        auto piece = Board::GetPieceAtPosition(position, board);
        if (piece.type != PIECETYPE_PAWN)
            return moves;

        int destination = piece.color == COLOR_WHITE ? 1 : -1;

        // handle regular move on to a empty Piece
        Position forward_one = {
            .rank = position.rank + destination,
            .file = position.file,
        };
        if (forward_one.IsValidPosition()
            && Board::GetPieceAtPosition(forward_one, board).type
                   == PIECETYPE_NIL)
        {
            moves.push_back({.curr = position,
                             .target = forward_one,
                             .type = MOVETYPE_MOVE,
                             .piece = piece});

            // since it can make one move, handle double move if
            // at initial rank
            int initial_rank = piece.color == COLOR_WHITE ? 1 : 6;
            if (position.rank == initial_rank)
            {
                Position forward_two = {
                    .rank = position.rank + 2 * destination,
                    .file = position.file,
                };
                if (forward_two.IsValidPosition()
                    && Board::GetPieceAtPosition(forward_two, board).type
                           == PIECETYPE_NIL)
                {
                    moves.push_back({.curr = position,
                                     .target = forward_two,
                                     .type = MOVETYPE_MOVE,
                                     .piece = piece});
                }
            }
        }

        // handle capture
        Position capture_positions[2] = {
            {.rank = position.rank + destination, .file = position.file - 1},
            {.rank = position.rank + destination, .file = position.file + 1}
        };
        for (Position capture_position : capture_positions)
        {
            if (!capture_position.IsValidPosition())
                continue;
            Piece piece_at_target =
                Board::GetPieceAtPosition(capture_position, board);
            if (piece_at_target.type != PIECETYPE_NIL
                && piece.color != piece_at_target.color)
            {
                moves.push_back({.curr = position,
                                 .target = capture_position,
                                 .type = MOVETYPE_CAPTURE,
                                 .piece = piece});
            }
        }

        return moves;
    }

    Moves GetMovesForPieceAt(const Position position, const BoardArray &board)
    {
        auto moves = Moves();
        Moves pawn_moves = GetPawnMovesForPieceAt(position, board);
        moves.insert(moves.begin(), pawn_moves.begin(), pawn_moves.end());

        Piece piece = Board::GetPieceAtPosition(position, board);
        if (piece.type == PIECETYPE_NIL || piece.type == PIECETYPE_PAWN)
        {
            return moves;
        }
        int move_limit =
            piece.type == PIECETYPE_KING || piece.type == PIECETYPE_KNIGHT ? 1
                                                                           : 8;
        auto move_destinations = GetPieceMoveDestinations(piece.type);

        for (auto destination : move_destinations)
        {
            int i = 1;
            for (i = 1; i < move_limit + 1; i++)
            {
                Position target_position = {
                    .rank = position.rank + (destination.rank * i),
                    .file = position.file + (destination.file * i)};

                if (target_position.IsValidPosition())
                {
                    Piece piece_at_target =
                        Board::GetPieceAtPosition(target_position, board);

                    if (piece_at_target.type == PIECETYPE_NIL)
                    {
                        // Empty Piece
                        moves.push_back({.curr = position,
                                         .target = target_position,
                                         .type = MOVETYPE_MOVE,
                                         .piece = piece});
                    } else
                    {
                        if (piece_at_target.color != piece.color)
                        {
                            // Opponent at target Piece
                            moves.push_back({.curr = position,
                                             .target = target_position,
                                             .type = MOVETYPE_CAPTURE,
                                             .piece = piece});
                        }
                        break;
                    }
                }
            }
        }
        return moves;
    }

    Moves GetRegularMoves(const Color turn, const BoardArray &board)
    {
        Moves moves;
        for (int rank = 7; rank >= 0; --rank)
        {
            for (int file = 0; file < 8; ++file)
            {
                Position position = {.rank = rank, .file = file};
                Piece piece_at_position =
                    Board::GetPieceAtPosition(position, board);
                if (piece_at_position.color == turn)
                {
                    Moves moves_at_Piece = GetMovesForPieceAt(position, board);
                    moves.insert(moves.end(),
                                 moves_at_Piece.begin(),
                                 moves_at_Piece.end());
                }
            }
        }
        return moves;
    }

    Moves GetEnpassantCaptures(const Position enpassant_target,
                               const BoardArray &board)
    {
        auto moves = Moves();
        int capture_rank;
        if (enpassant_target.rank == 5)
            capture_rank = (short)4;
        else if (enpassant_target.rank == 2)
            capture_rank = (short)3;
        else
            return moves;

        auto capture_piece = Board::GetPieceAtPosition(
            {.rank = capture_rank, .file = enpassant_target.file}, board);

        Position positions[2] = {
            {.rank = capture_rank, .file = enpassant_target.file + 1},
            {.rank = capture_rank, .file = enpassant_target.file - 1},
        };
        for (auto position : positions)
        {
            if (position.IsValidPosition())
            {
                Piece piece = Board::GetPieceAtPosition(position, board);
                if (piece.color != capture_piece.color
                    && piece.type != PIECETYPE_NIL)
                {
                    moves.push_back({.curr = position,
                                     .target = enpassant_target,
                                     .type = MOVETYPE_ENPASSANT,
                                     .piece = piece});
                    // cout << position.GetPositionCode() << " "
                    //      << piece.GetPieceCode() << " " << 1 << "\n";
                }
            }
        }
        cout << "Enpassant Captures " << moves.size() << "\n";
        return moves;
    }

    Moves GetAllMoves(const BoardState &state)
    {
        auto moves = GetRegularMoves(state.turn, state.board);

        auto enpassant_captures =
            GetEnpassantCaptures(state.enpassant_target, state.board);
        moves.insert(
            moves.end(), enpassant_captures.begin(), enpassant_captures.end());

        auto castling_moves =
            GetCastlingMoves(state.turn, state.castling_rights, state.board);
        moves.insert(moves.end(), castling_moves.begin(), castling_moves.end());

        return moves;
    }

    Moves GetLegalMoves(const BoardState &state)
    {
        auto moves = GetRegularMoves(state.turn, state.board);

        auto enpassant_captures =
            GetEnpassantCaptures(state.enpassant_target, state.board);
        moves.insert(
            moves.end(), enpassant_captures.begin(), enpassant_captures.end());

        auto castling_moves =
            GetCastlingMoves(state.turn, state.castling_rights, state.board);
        moves.insert(moves.end(), castling_moves.begin(), castling_moves.end());

        auto validMoves = FilterMovesThatLandKingInCheck(moves, state);
        cout << "Total Moves " << moves.size() << "\n";
        cout << "Legal Moves " << validMoves.size() << "\n";
        return validMoves;
    }

    Moves FilterMovesThatLandKingInCheck(Moves &moves, const BoardState &state)
    {
        Moves validMoves;
        for (auto move : moves)
        {
            BoardState new_state = Board::NewBoardAfterMove(move, state);
            if (!Board::IsKingInCheck(state.turn, new_state.board))
            {
                validMoves.push_back(move);
                // cout << move.curr.GetPositionCode() << " "
                //      << move.target.GetPositionCode() << " "
                //      << Board::getSimpleValueForBoard(new_board) << "\n";
            } else
            {
                // cout << move.curr.GetPositionCode() << " "
                //      << move.target.GetPositionCode() << " "
                //      << Board::getSimpleValueForBoard(new_board) << "\n";
            }
        }
        return validMoves;
    }

    Moves GetCastlingMoves(const Color turn,
                           const CastlingRights castling_rights,
                           const BoardArray &board)
    {
        Moves moves;
        int king_file = 4;
        int rank = turn == COLOR_WHITE ? 0 : 7;
        bool king_side_allowed = turn == COLOR_WHITE
                                     ? castling_rights.white_king_side
                                     : castling_rights.black_king_side;
        bool queen_side_allowed = turn == COLOR_WHITE
                                      ? castling_rights.white_queen_side
                                      : castling_rights.black_queen_side;

        if (Board::IsKingInCheckAt(
                turn, {.rank = rank, .file = king_file}, board))
            return moves;

        int king_target_file = -1;
        int passover_file = -1;

        bool isEmpty;
        bool kingWillBeInCheckPassingOver;
        Piece king_piece =
            GetPieceAtPosition({.rank = rank, .file = king_file}, board);
        if (king_side_allowed)
        {
            king_target_file = 6;
            passover_file = 5;
            isEmpty =
                Board::IsPositionEmpty({.rank = rank, .file = 5}, board)
                && Board::IsPositionEmpty({.rank = rank, .file = 6}, board);
            if (isEmpty)
            {
                kingWillBeInCheckPassingOver = Board::IsKingInCheckAt(
                    turn, {.rank = rank, .file = passover_file}, board);
                if (!kingWillBeInCheckPassingOver)
                {
                    moves.push_back({
                        .curr = {.rank = rank, .file = king_file       },
                        .target = {.rank = rank, .file = king_target_file},
                        .type = MOVETYPE_CASTLING,
                        .piece = king_piece
                    });
                }
            }
        }
        if (queen_side_allowed)
        {
            king_target_file = 2;
            passover_file = 3;
            isEmpty =
                Board::IsPositionEmpty({.rank = rank, .file = 1}, board)
                && Board::IsPositionEmpty({.rank = rank, .file = 2}, board)
                && Board::IsPositionEmpty({.rank = rank, .file = 3}, board);
            if (isEmpty)
            {
                kingWillBeInCheckPassingOver = Board::IsKingInCheckAt(
                    turn, {.rank = rank, .file = passover_file}, board);
                if (!kingWillBeInCheckPassingOver)
                {
                    moves.push_back({
                        .curr = {.rank = rank, .file = king_file       },
                        .target = {.rank = rank, .file = king_target_file},
                        .type = MOVETYPE_CASTLING,
                        .piece = king_piece
                    });
                }
            }
        }
        // cout << "Castling Moves " << moves.size() << "\n";
        return moves;
    }

    Move GetBestMove(const BoardState &state)
    {
        auto moves = Board::GetAllMoves(state);
        moves = Board::FilterMovesThatLandKingInCheck(moves, state);
        if (moves.size() == 0)
        {
            return {
                .curr = {.rank = -1,            .file = -1        },
                .piece = {.type = PIECETYPE_NIL, .color = COLOR_NIL}
            };
        }
        vector<int> evals;
        for (const auto move : moves)
        {
            int eval = EvaluateMoveWithMinMax(move, state);
            evals.push_back(eval);
        }
        sort_by_order(moves, evals, false);

        const Move best = moves[0];
        return best;
    }

} // namespace Board