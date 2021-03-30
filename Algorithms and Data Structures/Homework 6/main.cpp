#include "Heap.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <iomanip>
using namespace std::chrono;



std::vector<int> generateVector(int size);
const double nano = 1000000000.0;

int main(void) {   
    // measuring execution time of Normal Heapsort for different array sizes.
    std::ofstream normal_heapsort("normal_heapsort.txt");

    for (int i = 0; i < 1000001; i += 5000) {
        std::vector<int> num_vector = generateVector(i);
        Heap heap = Heap(num_vector);

        auto begin = high_resolution_clock::now();
        heap.heapSort();
        auto end = high_resolution_clock::now();

        auto elapsed = duration_cast<nanoseconds>(end - begin);
        
        normal_heapsort << i << " " << elapsed.count() / nano << std::endl;
    }
    normal_heapsort.close();



    // measuring execution time of Bottom-Up Heapsort for different array sizes.

    std::ofstream bottomup_heapsort("bottomup_heapsort.txt");
    
    for (int i = 0; i < 1000001; i += 5000) {
        std::vector<int> num_vector = generateVector(i);
        Heap heap = Heap(num_vector);

        auto begin = high_resolution_clock::now();
        heap.bottomUpHeapSort();
        auto end = high_resolution_clock::now();

        auto elapsed = duration_cast<nanoseconds>(end - begin);

        bottomup_heapsort << i << " " << elapsed.count() / nano << std::endl;
    }
    bottomup_heapsort.close();

    return 0;
}


std::vector<int> generateVector(int size) {
    srand(time(0));
    std::vector<int> newVector;
    for (int i = 0; i < size; i++)
        newVector.push_back(rand());
    return newVector;
}
