//
// Created by Danijel Tomić on 12. 05. 24.
//

#include "ReferenceCounter.h"
ReferenceCounter::ReferenceCounter()
    : count(0)
{
}
ReferenceCounter& ReferenceCounter::operator++(int)
{
    count++;
    return *this;
}
ReferenceCounter& ReferenceCounter::operator--()
{
    if (count > 0)
        count--;
    return *this;
}
bool operator==(const ReferenceCounter& ref, const int& count)
{
    return ref.count == count;
}
