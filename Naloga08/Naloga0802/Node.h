//
// Created by danijel on 5/5/2024.
//

#ifndef PROGRAMIRANJE2_NODE_H
#define PROGRAMIRANJE2_NODE_H

#include <memory>

template <class T>
class Node
{
    using NodePtr = std::shared_ptr<Node<T>>;

private:
    T value;
    NodePtr next;

public:
    Node(T Value, NodePtr next)
        : value(value)
        , next(next)
    {
    }

    ~Node()
    {
        next = nullptr;
    }
    T getValue() const
    {
        return value;
    }
    void setValue(T value)
    {
        this->value = value;
    }
    NodePtr getNext() const
    {
        return next;
    }
    void setNext(NodePtr next)
    {
        this->next = std::move(next);
    }
};

#endif  // PROGRAMIRANJE2_NODE_H
