#include "../chessai.hpp"
using namespace std;

string Move::GetChars()
{
    const map<MoveType, string> move_type_map = {
        {MOVETYPE_NIL,         "NIL"        },
        {MOVETYPE_MOVE,        "MOVE"       },
        {MOVETYPE_DOUBLE_MOVE, "DOUBLE_MOVE"},
        {MOVETYPE_CAPTURE,     "CAPTURE"    },
        {MOVETYPE_ENPASSANT,   "ENPASSANT"  },
        {MOVETYPE_PROMOTE,     "PROMOTE"    },
        {MOVETYPE_CASTLING,    "CASTLING"   }
    };
    return this->curr.GetPositionCode() + ' ' + this->piece.GetPieceCode() + ' '
           + this->target.GetPositionCode() + ' '
           + move_type_map.at(this->type);
}