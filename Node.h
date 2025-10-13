//
// Created by gusw1 on 10/13/2025.
//

#ifndef DMSIM_NODE_H
#define DMSIM_NODE_H

template<typename T>
class Node {
    Node *next;
    Node *prev;
    T data;

public:
    Node(Node *next, Node *prev, const T &data)
        : next(next), prev(prev), data(data) {
    }

    explicit Node(const T &data)
        : next(nullptr), prev(nullptr), data(data) {
    }


    T &getData() { return data; }
    Node *getNext() { return next; }
    Node *getPrev() { return prev; }
    void setNext(Node *newNode) { next = newNode; }
    void setPrev(Node *newNode) { prev = newNode; }
};


#endif //DMSIM_NODE_H