//
// Created by Danijel Tomić on 12. 05. 24.
//

#ifndef PROGRAMIRANJE2_SMARTPOINTER_H
#define PROGRAMIRANJE2_SMARTPOINTER_H
#include "ReferenceCounter.h"

template <class T>
class SmartPointer
{
private:
    T* ptr;
    ReferenceCounter* refCount;

public:
    explicit SmartPointer(T* p = nullptr)
        : ptr(p)
        , refCount(new ReferenceCounter)
    {
        (*refCount)++;
    }

    SmartPointer(const SmartPointer<T>& sp)
        : ptr(sp.ptr)
        , refCount(sp.refCount)
    {
        (*refCount)++;
    }

    SmartPointer& operator=(const SmartPointer<T>& sp)
    {
        if (this != &sp)
        {
            if (--(*refCount) == 0)
            {
                delete ptr;
                delete refCount;
            }

            ptr = sp.ptr;
            refCount = sp.refCount;
            (*refCount)++;
        }
        return *this;
    }

    T& operator*() const
    {
        return *ptr;
    }

    T* operator->() const
    {
        return ptr;
    }

    ~SmartPointer()
    {
        if (--(*refCount) == 0)
        {
            delete ptr;
            delete refCount;
        }
    }

    int useCount() const
    {
        return refCount->count;
    }
};

#endif  // PROGRAMIRANJE2_SMARTPOINTER_H
