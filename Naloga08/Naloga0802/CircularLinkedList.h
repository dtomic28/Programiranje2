//
// Created by danijel on 5/5/2024.
//

#ifndef PROGRAMIRANJE2_CIRCULARLINKEDLIST_H
#define PROGRAMIRANJE2_CIRCULARLINKEDLIST_H
#include "Node.h"
#include <stdexcept>
template <class T>
class CircularLinkedList
{
private:
    using NodePtr = std::shared_ptr<Node<T>>;
    NodePtr head;
    NodePtr tail;
    unsigned int count;

public:
    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~CircularLinkedList()
    {
        NodePtr current = head;
        while (current != nullptr)
        {
            NodePtr next = current->getNext();
            current.reset();
            current = next;
        }
        head.reset();
        tail.reset();
    }

    bool isEmpty()
    {
        return count == 0;
    }

    unsigned int getSize()
    {
        return count;
    }

    void add(T value)
    {
        count++;
        NodePtr temp = std::make_shared<Node<T>>(value, nullptr);
        if (head == nullptr && tail == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->setNext(temp);
            tail = temp;
        }
    }

    T at(unsigned int index)
    {
        if (index >= count)
            throw std::out_of_range("Index larger than linked list");

        NodePtr current = head;
        for (unsigned int i = 0; i < index; ++i)
        {
            if (!current)
                throw std::out_of_range("Index larger than linked list");
            current = current->getNext();
        }
        return current->getValue();
    }
};

#endif  // PROGRAMIRANJE2_CIRCULARLINKEDLIST_H
