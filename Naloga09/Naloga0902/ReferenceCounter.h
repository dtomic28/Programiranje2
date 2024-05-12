//
// Created by Danijel Tomić on 12. 05. 24.
//

#ifndef PROGRAMIRANJE2_REFERENCECOUNTER_H
#define PROGRAMIRANJE2_REFERENCECOUNTER_H

class ReferenceCounter
{
    friend bool operator==(const ReferenceCounter& ref, const int& count);

public:
    int count;

    ReferenceCounter();

    ReferenceCounter& operator++(int);

    // Prefix decrement operator
    ReferenceCounter& operator--();
};

#endif  // PROGRAMIRANJE2_REFERENCECOUNTER_H
