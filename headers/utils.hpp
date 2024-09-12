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

template <typename T>
void sort_by_order(std::vector<T>& data, const std::vector<int>& order, bool ascending = true)
{
    // Check if the order vector size
    // matches data vector size
    if (order.size() != data.size()) {
        std::cerr << "Error: 'order' vector size must match 'data' vector size."
                  << std::endl;
        return;
    }

    // Create an index vector representing the indices of the 'data' vector
    std::vector<int> indices(data.size());
    for (size_t i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }

    // Sort the indices based on the values in the order vector
    std::sort(indices.begin(), indices.end(),
        [&order, ascending](int a, int b) {
            return ascending ? order[a] < order[b] : order[b] < order[a];
        });

    // Create a temporary vector to hold sorted data
    std::vector<T> sorted_data(data.size());

    // Rearrange data according to sorted indices
    for (size_t i = 0; i < indices.size(); ++i) {
        sorted_data[i] = data[indices[i]];
    }

    // Move sorted data back to the original data vector
    data = std::move(sorted_data);
}