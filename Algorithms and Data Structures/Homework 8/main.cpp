#include <iostream>
#include <vector>
#include "CountingSort.cpp"
#include "BucketSort.cpp"
#include "StringSort.cpp"
#include "HollerithRadixSort.cpp"

template <class T>
void printVector(std::vector<T> v);

void printArray(int arr[], int dim);


int main() {
    // question 8.1 (a)
    std::cout << "Sorting using Counting sort." << std::endl;
    int array[] = {9, 1, 6, 7, 6, 2, 1};
    int* result = countingSort(array, 7, 10);
    std::cout << "Unsorted : ";
    printArray(array, 7);
    std::cout << "Sorted   : ";
    printArray(result, 7);

    // question 8.1 (b)
    std::cout << "\nSorting using Bucket sort." << std::endl;
    std::vector<double> doubles = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    std::cout << "Unsorted : ";
    printVector(doubles);
    BucketSort(doubles);
    std::cout << "Sorted   : ";
    printVector(doubles);

    // question 8.1 (d)
    std::cout << "\nSorting strings in theta(n) time." << std::endl;
    std::vector<std::string> words = {"word", "category", "cat", "new", "news",
    "world", "bear", "at", "work", "time"};
    std::cout << "Unsorted : ";
    printVector(words);
    StringSort(words);
    std::cout << "Sorted   : ";
    printVector(words);

    // question 8.2 (a)
    std::cout << "\nSorting numbers using Hollerith's Radix Sort."<< std::endl;
    std::vector<int> numbers = {123, 92, 581, 1, 62, 1234, 90, 384, 8, 1111};
    std::cout << "Unsorted : ";
    printVector(numbers);
    HollerithRadixSort(numbers);
    std::cout << "Sorted   : ";
    printVector(numbers);    
    
    return 0;
}   




void printArray(int arr[], int dim) {
    std::cout << "[";
    for (int i = 0; i < dim - 1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[dim - 1] << "]" << std::endl;
}

template <class T>
void printVector(std::vector<T> v) {
    std::cout << "[";
    for (unsigned int i = 0; i < v.size() - 1; i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << v[v.size() - 1] << "]" << std::endl;
}