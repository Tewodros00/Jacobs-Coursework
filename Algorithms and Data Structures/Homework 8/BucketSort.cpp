#include <vector>
#include <algorithm>

void BucketSort(std::vector<double> &array) {
    std::vector<std::vector<double>> buckets;

    for (unsigned int i = 0; i < array.size(); i++)
        buckets.push_back(std::vector<double>{});

    for (double num : array) {
        int index = num / (1.0f / array.size());
        buckets[index].push_back(num);
    }

    array.clear();

    for (unsigned int i = 0; i < buckets.size(); i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
        array.insert(array.end(), buckets[i].begin(), buckets[i].end());
    }
}