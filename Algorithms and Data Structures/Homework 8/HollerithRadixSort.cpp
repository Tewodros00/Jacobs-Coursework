#include <vector>
#include <iostream>
#include <cmath>
#include <string>

void HollerithRadixSortHelper(std::vector<int> &numbers, int index, 
            int maxDigit) {
    if (numbers.size() <= 1 || index >= maxDigit) {
        return;
    }

    std::vector<std::vector<int>> buckets;
    buckets.reserve(10);
    for (int i = 0; i < 10; i++)
        buckets.emplace_back();

    for (int number : numbers) {
        int sorting_digit = 
            static_cast<int>(number / pow(10, maxDigit - index - 1)) % 10;
        buckets[sorting_digit].push_back(number);
    }

    numbers.clear();
    for (unsigned int i = 0; i < buckets.size(); i++) {
        HollerithRadixSortHelper(buckets[i], index + 1, maxDigit);
        numbers.insert(numbers.end(), buckets[i].begin(), buckets[i].end());
    }
}

void HollerithRadixSort(std::vector<int> &numbers) {
    int maxDigit = 0;
    for (int number : numbers) {
        int length = std::to_string(number).length();
        if (maxDigit < length) 
            maxDigit = length;
    }
    
    HollerithRadixSortHelper(numbers, 0, maxDigit);
}