//
// Created by Ethan Wong on 3/23/23.
//

#ifndef CS008MIDTERMPROJECT_HEAP_H
#define CS008MIDTERMPROJECT_HEAP_H

#include <vector>
#include <iostream>

template <typename T>
class Heap {
private:
    std::vector<T> heap;

    int getParent(int childIndex);
    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);
    int getMaxChild(int parentIndex);
    void reheapifyUp(int childIndex);
    void reheapifyDown(int parentIndex);
    void swap(int childIndex, int parentIndex);
public:
    Heap(const T& item);

    void push(const T& item);
    void pop();
    T top();
    int size();
    bool empty();

    void print();
};

#include "Heap.cpp"

#endif //CS008MIDTERMPROJECT_HEAP_H
