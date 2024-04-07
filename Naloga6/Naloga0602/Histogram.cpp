//
// Created by danijel on 4/7/2024.
//

#include "Histogram.h"
#include <iostream>
#include <algorithm>

Histogram::Histogram(const std::string& title, const std::vector<int>& data, int numBins)
    : Graph(title, data)
    , numBins(numBins)
{
}
void Histogram::show(ColorCode color)
{
    std::cout << title << std::endl;
    int min = getMinValue();
    int binRange = (getMaxValue() - min) / numBins;

    for (int i = 0; i < numBins; ++i)
    {
        int binMin = min + i * binRange;
        int binMax = (i == numBins - 1) ? getMaxValue() : binMin + binRange - 1;
        auto count = countItemsInRange(data, binMin, binMax);
        PrintUtility::print(ColorCode::Default, std::to_string(binMin) + " - " + std::to_string(binMax) + ": ");
        PrintUtility::printSequence(color, "*", count);
        std::cout << std::endl;
    }
}
int Histogram::countItemsInRange(std::vector<int> data, int low, int high)
{
    std::sort(data.begin(), data.end());
    auto left = lower_bound(data.begin(), data.end(), low);
    auto right = upper_bound(data.begin(), data.end(), high);
    int count = (int) (right - left);
    return count;
}
