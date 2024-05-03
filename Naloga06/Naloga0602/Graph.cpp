//
// Created by danijel on 4/7/2024.
//
#include "Graph.h"
#include <algorithm>

Graph::Graph(const std::string& title, const std::vector<int>& data)
    : title(title)
    , data(data)
{
}
Graph::Graph()
    : title("Graph")
{
}
Graph::Graph(const Graph& graph) = default;

int Graph::getMaxValue() const
{
    return *(std::max_element(data.begin(), data.end()));
}
int Graph::getMinValue() const
{
    return *(std::min_element(data.begin(), data.end()));
}
