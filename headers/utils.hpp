#pragma once

#include <vector>
using namespace std;

template <typename T>
vector<T> Concatenate(vector<T>& vec1, vector<T>& vec2)
{
    vector<T> result = vec1;
    result.insert(result.end(), vec2.begin(), vec2.end());
    return result;
}
