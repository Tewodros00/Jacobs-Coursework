#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<int> longestOrderedSubarray(std::vector<int> array);

int main() 
{
    // reading the numbers
    std::vector<int> numbers;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number;
    while (iss >> number)
    {
        numbers.push_back(number);
    }
    
    std::vector<int> subarray = longestOrderedSubarray(numbers);

    for (int a : subarray)
    {
        std::cout << a << " ";
    }
}



std::vector<int> longestOrderedSubarray(std::vector<int> array)
{
    std::vector<int> lis (array.size(), 1);

    // builds the vector 'lis' which contains the length of longest ordered 
    // subarray that can be built from the number at that index
    for (uint32_t i = 1; i < array.size(); i++)
    {
        for (uint32_t j = 0; j < i; j++)
        {
            if (array[i] > array[j] and lis[i] <= lis[j])
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max_subarray_length = *std::max_element(lis.begin(), lis.end());

    std::vector<int> result(max_subarray_length, 0);

    // builds the subarray by adding elements into result vector starting with 
    // elements which have a value of 'max_subarray_length' to 1 in 'lis'.
    int k = array.size() - 1;
    for (int i = max_subarray_length; i > 0; i--)
    {
        int index;
        for (uint32_t j = k; j >= 0; j--)
        {
            if (lis[j] == i)
            {
                index = j;
                k = j - 1;
                break;
            }
        }
        result[i - 1] = array[index];
    }

    return result;
}
