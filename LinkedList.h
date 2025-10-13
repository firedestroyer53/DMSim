//
// Created by gusw1 on 10/13/2025.
//

#ifndef DMSIM_LINKEDLIST_H
#define DMSIM_LINKEDLIST_H

#include <vector>
#include "Node.h"

template<typename T>
class LinkedList {
    Node<T> *front;
    Node<T> *back;

public:
    LinkedList();

    void pushBack(Node<T> *node); // insert at the end
    void pushFront(Node<T> *node); // insert at the front

    Node<T> *getFront() { return front; }
    Node<T> *getBack() { return back; }

    std::vector<T> toVector();
};

// ===== Template Implementations =====

template<typename T>
LinkedList<T>::LinkedList() {
    front = nullptr;
    back = nullptr;
}

template<typename T>
void LinkedList<T>::pushBack(Node<T> *node) {
    if (!back) {
        // list is empty
        front = node;
        back = node;
    } else {
        // list already has nodes
        back->setNext(node);
        node->setPrev(back);
        back = node;
    }
}

template<typename T>
void LinkedList<T>::pushFront(Node<T> *node) {
    if (!front) {
        // list is empty
        front = node;
        back = node;
    } else {
        // list already has nodes
        node->setNext(front);
        front->setPrev(node);
        front = node;
    }
}

template<typename T>
std::vector<T> LinkedList<T>::toVector() {
    std::vector<T> vec;
    Node<T> *current = front;
    while (current != nullptr) {
        vec.push_back(current->getData());
        current = current->getNext();
    }
    return vec;
}

#endif // DMSIM_LINKEDLIST_H
