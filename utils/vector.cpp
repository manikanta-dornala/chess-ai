#pragma once
#include <vector>
using namespace std;

template <typename T>
vector<T> Concatenate(const vector<T>& vec1, const vector<T>& vec2)
{
	vector<T> result = vec1;
	result.insert(result.end(), vec2.begin(), vec2.end());
	return result;
}

template <typename T>
list<T> Concatenate(const list<T>& vec1, const list<T>& vec2)
{
	list<T> result = vec1;
	result.insert(result.end(), vec2.begin(), vec2.end());
	return result;
}