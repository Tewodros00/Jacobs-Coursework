#include <iostream>
#include "Heap.h"

Heap::Heap(std::vector<int> arr)
{
    for (auto a : arr)
        heap.push_back(a);
    heapsize = (int)arr.size() - 1;
}

int Heap::parent(int i) { return ((i + 1) / 2) - 1;}
int Heap::left(int i) { return 2 * i + 1;}
int Heap::right(int i) { return 2 * i + 2;}

void Heap::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= heapsize and heap[l] > heap[i])
        largest = l;

    if (r <= heapsize and heap[r] > heap[largest])
        largest = r;
    
    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        maxHeapify(largest);
    }
}

void Heap::buildMaxHeap() {
    heapsize = heap.size() - 1;
    for (int i = (heap.size() / 2) - 1; i >= 0; i--)
        maxHeapify(i);
}

void Heap::heapSort() {
    buildMaxHeap();
    for (int i = heapsize; i >= 0; i--) {
        std::swap(heap[0], heap[i]);
        heapsize--;
        maxHeapify(0);
    }
}


int Heap::leafSearch(int i) {
    int j = i;
    while (right(j) <= heapsize) {
        if (heap[right(j)] > heap[left(j)])
            j = right(j);
        else
            j = left(j);
    }

    if (left(j) <= heapsize)
        j = left(j);
    return j;    
}

void Heap::siftDown(int i) {
    int j = leafSearch(i);
    while (heap[i] > heap[j]) // incase moving the element up is needed
        j = parent(j);

    int x = heap[j];
    heap[j] = heap[i];

    while (j > i) {
        std::swap(x, heap[parent(j)]);
        j = parent(j);
    }
}

void Heap::bottomUpHeapSort() {
    buildMaxHeap();
    for (int i = heapsize; i >= 0; i--) {
        std::swap(heap[0], heap[i]);
        heapsize--;
        siftDown(0);
    }
}

void Heap::printHeap() {
    for (auto num : heap) 
        std::cout << num << " ";
    std::cout << std::endl;
}