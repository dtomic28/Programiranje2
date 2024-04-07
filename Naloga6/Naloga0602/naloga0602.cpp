//
// Created by danijel on 4/7/2024.
//
#include <iostream>
#include "Histogram.h"

int main()
{
    using namespace std::string_literals;
    system(("chcp "s + std::to_string(65001)).c_str());

    std::vector<int> data1 = {5, 6, 10, 20, 16, 18, 9, 11, 12, 7, 7, 13};
    Histogram histogram1("Histogram of Results 1", data1, 3);
    histogram1.show(ColorCode::Blue);

    std::vector<int> data2 = {22, 18, 30, 35, 40, 28, 32, 31, 34, 29, 27, 38};
    Histogram histogram2("Histogram of Results 2", data2, 4);
    histogram2.show(ColorCode::Red);

    std::vector<int> data3 = {42, 46, 55, 60, 51, 65, 70, 68, 72, 74, 66, 64};
    Histogram histogram3("Histogram of Results 3", data3, 5);
    histogram3.show(ColorCode::Green);

    std::vector<int> data4 = {1, 2, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 9, 10};
    Histogram histogram4("Histogram of Results 4", data4, 2);
    histogram4.show(ColorCode::Default);

    return 0;
}