//
// Created by Ethan Wong on 3/23/23.
//

#ifndef CS008MIDTERMPROJECT_HEAP_CPP
#define CS008MIDTERMPROJECT_HEAP_CPP

#include "Heap.h"

template<typename T>
int Heap<T>::getParent(int childIndex) {
    return (((childIndex+1)/2)-1);
}

template<typename T>
int Heap<T>::getLeftChild(int parentIndex) {
    return (((parentIndex+1)*2)-1);
}

template<typename T>
int Heap<T>::getRightChild(int parentIndex) {
    return ((parentIndex+1)*2);
}

template<typename T>
int Heap<T>::getMaxChild(int parentIndex) {
    int leftIndex = getLeftChild(parentIndex);
    int rightIndex = getRightChild(parentIndex);
    if (leftIndex >= size())
        return parentIndex;
    else if (rightIndex >= size()) {
        if (heap[leftIndex] > heap[parentIndex])
            return leftIndex;
        else
            return parentIndex;
    }
    else {
        if (heap[parentIndex] > heap[leftIndex] && heap[parentIndex] > heap[rightIndex])
            return parentIndex;
        else if (heap[leftIndex] >= heap[rightIndex])
            return leftIndex;
        else
            return rightIndex;
    }

    /*
    T& parent = heap.at(parentIndex);
    T& left = heap.at(getLeftChild(parentIndex));
    if (size()%2 == 0) {
        if (parent > left)
            return parentIndex;
        else
            return getLeftChild(parentIndex);
    }
    else {
        T& right = heap.at(getRightChild(parentIndex));
        if (parent > left && parent > right)
            return parentIndex;
        else if (left > right)
            return getLeftChild(parentIndex);
        else
            return getRightChild(parentIndex);
    }
     */
}

template<typename T>
void Heap<T>::reheapifyUp(int childIndex) {
    int parentIndex = getParent(childIndex);
    if (heap[childIndex] > heap[parentIndex]) {
        swap(childIndex, parentIndex);
        if (parentIndex != 0)
            reheapifyUp(parentIndex);
    }
}

template<typename T>
void Heap<T>::reheapifyDown(int parentIndex) {
    int childIndex = getMaxChild(parentIndex);
    if (heap[childIndex] > heap[parentIndex]) {
        swap(childIndex, parentIndex);
        reheapifyDown(childIndex);
    }
}

template<typename T>
void Heap<T>::swap(int childIndex, int parentIndex) {
    std::swap(heap[childIndex], heap[parentIndex]);
}

template<typename T>
Heap<T>::Heap(const T& item) {
    heap.push_back(item);
}

template<typename T>
void Heap<T>::push(const T &item) {
    heap.push_back(item);
    reheapifyUp(size()-1);
}

template<typename T>
void Heap<T>::pop() {
    heap.pop_back();
    reheapifyDown(0);
}

template<typename T>
T Heap<T>::top() {
    /*
    swap(0,size()-1);
    reheapifyDown(0);
    print();
    return heap.front();
     */
    T saved = heap.front();
    swap(0,size()-1);
    pop();
    reheapifyDown(0);
    heap.push_back(saved);
    return saved;
}

template<typename T>
int Heap<T>::size() {
    return heap.size();
}

template<typename T>
bool Heap<T>::empty() {
    return heap.empty();
}

template<typename T>
void Heap<T>::print() {
    for (T item : heap)
        std::cout << item << " ";
    std::cout << std::endl;
}

#endif //CS008HEAPS_HEAP_CPP
