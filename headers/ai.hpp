#pragma once
#include <iostream>
#include <list>

#include "enums.hpp"
#include "structs.hpp"
#include "utils.hpp"
using namespace std;

namespace AI
{
    int minmax(const BoardArray &board,
               const Color &turn,
               const int depth,
               int alpha,
               int beta);
}