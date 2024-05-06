//
// Created by danijel on 5/5/2024.
//
#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main()
{
    CircularLinkedList<int> myList;

    // Testing isEmpty() method
    std::cout << "Is list empty? " << (myList.isEmpty() ? "Yes" : "No") << std::endl;

    // Testing add() method
    myList.add(5);
    myList.add(10);
    myList.add(10);
    myList.add(15);

    // Testing getSize() method
    std::cout << "List size: " << myList.getSize() << std::endl;

    // Testing at() method
    try
    {
        std::cout << "Value at index 1: " << myList.at(1) << std::endl;
        myList.removeAt(3);
        std::cout << myList.getSize() << endl;
        std::cout << myList.at(3);
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}