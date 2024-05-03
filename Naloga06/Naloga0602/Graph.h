//
// Created by danijel on 4/7/2024.
//

#ifndef PROGRAMIRANJE2_GRAPH_H
#define PROGRAMIRANJE2_GRAPH_H
#include "PrintUtility.h"
#include <vector>

class Graph
{
public:
    Graph(const std::string& title, const std::vector<int>& data);
    Graph();
    Graph(const Graph& graph);

    int getMaxValue() const;
    int getMinValue() const;

    virtual void show(ColorCode color) = 0;

protected:
    std::string title;
    std::vector<int> data;
};

#endif  // PROGRAMIRANJE2_GRAPH_H
