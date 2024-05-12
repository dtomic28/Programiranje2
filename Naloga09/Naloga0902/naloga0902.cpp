//
// Created by Danijel Tomić on 12. 05. 24.
//
#include <iostream>
#include "SmartPointer.h"
#include "Date.h"

using namespace std;

int main()
{
    SmartPointer<Date> date1(new Date(1, 1, 2020));
    SmartPointer<Date> date2(new Date(1, 1, 2019));
    date2 = date1 = date1 = date1 = date1 = date1;  // tukaj se kliče operator =
    date2 = date2;
    date2 = date2;
    std::cout << "reference count: " << date2.useCount() << std::endl;
    return 0;
}