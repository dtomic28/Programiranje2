//
// Created by danijel on 5/3/2024.
//
#include <iostream>
#include "PriorityQueue.h"
#include "time.h"
#include <memory>

using namespace std;

int main()
{
    PriorityQueue<Time> queueTime;
    queueTime.add(Time(10, 30, 0), Priority::High);
    queueTime.add(Time(9, 45, 15), Priority::Low);
    queueTime.add(Time(11, 0, 0), Priority::High);

    PriorityQueue<std::shared_ptr<Time>> queueSharedPtr;
    queueSharedPtr.add(std::make_shared<Time>(10, 30, 0), Priority::High);
    queueSharedPtr.add(std::make_shared<Time>(9, 45, 15), Priority::Low);
    queueSharedPtr.add(std::make_shared<Time>(11, 0, 0), Priority::High);

    // Uporaba z int
    PriorityQueue<int> queueInt;
    queueInt.add(10, Priority::High);
    queueInt.add(5, Priority::Low);
    queueInt.add(20, Priority::High);

    // Uporaba z string
    PriorityQueue<std::string> queueString;
    queueString.add("Apple", Priority::High);
    queueString.add("Banana", Priority::Low);
    queueString.add("Cherry", Priority::High);

    try
    {
        // Demonstracija pop in getMax za Time
        std::cout << "Max Time: " << queueTime.getMax().toString() << std::endl;
        std::cout << "Popped Time: " << queueTime.pop().toString() << std::endl;

        // Demonstracija pop in getMax za std::shared_ptr<Time>
        std::cout << "Max Shared Time: " << queueSharedPtr.getMax()->toString() << std::endl;
        std::cout << "Popped Shared Time: " << queueSharedPtr.pop()->toString() << std::endl;

        // Demonstracija pop in getMax za int
        std::cout << "Max int: " << queueInt.getMax() << std::endl;
        std::cout << "Popped int: " << queueInt.pop() << std::endl;

        // Demonstracija pop in getMax za string
        std::cout << "Max string: " << queueString.getMax() << std::endl;
        std::cout << "Popped string: " << queueString.pop() << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}