#pragma once
#include <iostream>
#include <list>

#include "enums.hpp"
#include "structs.hpp"
#include "utils.hpp"
using namespace std;

namespace AI
{

    MinMaxEval
    minmax(const BoardState state, const int depth, int alpha, int beta);
} // namespace AI