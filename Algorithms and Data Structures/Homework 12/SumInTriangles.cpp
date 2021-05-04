#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


int main()
{
    std::vector<std::vector<int>> triangle;

    int line_number = 0;
    std::string line;
    std::getline(std::cin, line);
    // read any number of lines that less than 100 lines
    while (line.length() and line_number <= 100)
    {
        triangle.emplace_back();
        std::istringstream iss(line);
        int number;
        while (iss >> number)
        {
            triangle[line_number].push_back(number);
        }
        std::getline(std::cin, line);
        line_number++;
    }
    
    // copy the triangle vector for the sum using the copy constructor
    std::vector<std::vector<int>> sum(triangle);
    
    // building a sum vector from bottom up starting with second to last row 
    // with each iteration adding the maximum of the numbers left or right 
    // below it.
    for (int i = line_number - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            sum[i][j] += std::max(sum[i+1][j], sum[i+1][j+1]);
        }
    }

    // when the above iteration is done the max path sum will be at the top
    std::cout << sum[0][0] << "\n";

    int idx = 0;
    // starting at the top and going down left or right based on which path has
    // the largest sum 
    for (unsigned int i = 0; i < sum.size(); i++)
    {
        if (sum[i][idx] < sum[i][idx + 1])
        {
            idx++;
        }
        std::cout << triangle[i][idx] << " "; // prints value at the path
    }

    std::cout << std::endl;
}