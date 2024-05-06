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
            current->setNext(nullptr);
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
        NodePtr temp = std::shared_ptr<Node<T>>(new Node<T>(value, nullptr));
        if (head == nullptr && tail == nullptr)
        {
            head = temp;
            tail = temp;
            tail->setNext(temp);
        }
        else
        {
            tail->setNext(temp);
            tail = temp;
            tail->setNext(head);
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

    void removeAt(unsigned int index)
    {
        if (index >= count)
            throw std::out_of_range("Index larger than linked list");
        NodePtr current = head;
        NodePtr prev, after;
        for (unsigned int i = 0; i < index; ++i)
        {
            if (!current)
                throw std::out_of_range("Index larger than linked list");
            current = current->getNext();
            if (i == index - 2)
            {
                prev = current;
            }
        }
        if (index != count - 1)
        {
            after = current->getNext();
            prev->setNext(after);
        }
        else
        {
            prev->setNext(nullptr);
        }
        current.reset();
        count--;
    }
};

#endif  // PROGRAMIRANJE2_CIRCULARLINKEDLIST_H
