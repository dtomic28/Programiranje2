//
// Created by danijel on 5/3/2024.
//

#ifndef PROGRAMIRANJE2_PRIORITYQUEUE_H
#define PROGRAMIRANJE2_PRIORITYQUEUE_H
#include <vector>
#include <stdexcept>
#include <algorithm>

enum class Priority
{
    High,
    Low
};

template <class T>
class PriorityQueue
{
private:
    std::vector<T> values;
    int indexNextHigh;

public:
    PriorityQueue()
    {
        indexNextHigh = 0;
    }

    bool isEmpty() const
    {
        return values.empty();
    }
    unsigned int size() const
    {
        return values.size();
    }
    void add(T value, Priority priority)
    {
        if (priority == Priority::High)
        {
            values.insert(values.begin() + indexNextHigh, value);
            indexNextHigh++;
        }
        else
        {
            values.push_back(value);
        }
    }
    T pop()
    {
        if (values.empty())
            throw std::out_of_range("Queue is empty");

        T result = values.front();
        values.erase(values.begin());
        if (indexNextHigh > 0)
            indexNextHigh--;
        return result;
    }
    T getMax()
    {
        if (values.empty())
            throw std::out_of_range("Queue is empty");

        return *max_element(values.begin(), values.end());
    }
};

#endif  // PROGRAMIRANJE2_PRIORITYQUEUE_H
