//
// Created by danijel on 4/7/2024.
//

#ifndef PROGRAMIRANJE2_HISTOGRAM_H
#define PROGRAMIRANJE2_HISTOGRAM_H

#include "Graph.h"

class Histogram : public Graph
{
public:
    Histogram(const std::string& title, const std::vector<int>& data, int numBins);

    void show(ColorCode color) override;

    static int countItemsInRange(std::vector<int> data, int low, int high);

private:
    int numBins;
};

#endif  // PROGRAMIRANJE2_HISTOGRAM_H
