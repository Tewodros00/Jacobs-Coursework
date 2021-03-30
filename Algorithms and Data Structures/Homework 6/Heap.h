#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap
{
private:
    int heapsize;
    std::vector<int> heap;
    
    int parent(int);
    int left(int);
    int right(int);
    int leafSearch(int);
    void siftDown(int);
public:
    Heap(std::vector<int>);

    void maxHeapify(int);
    void buildMaxHeap();
    void heapSort();
    void bottomUpHeapSort();
    void printHeap();

};



#endif