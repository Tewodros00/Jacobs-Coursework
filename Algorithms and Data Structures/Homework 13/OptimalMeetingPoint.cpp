#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

#define INF std::numeric_limits<int>::max()
#define city_pair std::pair<int, int>

struct compare
{
    bool operator() (const city_pair &city_one, const city_pair &city_two) 
    {
        return city_one.second > city_two.second;
    }
};

int find_meetup_city(const std::vector<std::vector<int>> &adj_matrix, 
        int your_city, int friend_city);

int main()
{
    int size;
    std::cout << "Enter the number of cities: ";
    std::cin >> size;

    std::vector<std::vector<int>> adjMatrix(size, std::vector<int>(size, 0));
    
    std::cout << "Fill the adjacency matrix\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << "distance[" << i << "][" << j <<"]: ";
            std::cin >> adjMatrix[i][j];
        }   
    }

    std::cout << "\nEnter the cities.\n";
    int yourCity, friendCity;
    std::cout << "Your city: ";
    std::cin >> yourCity;
    std::cout << "Friend city: ";
    std::cin >> friendCity;

    int city = find_meetup_city(adjMatrix, yourCity, friendCity);

    std::cout << "\nThe optimal meeting point is city " << city << ".\n";
}

int find_meetup_city(const std::vector<std::vector<int>> &adj_matrix, 
        int your_city, int friend_city)
{
    int size = adj_matrix.size();

    // using Dijkstra's algorithm to find the shortest distance from your_city
    // to all cities in the graph and storing it in yourDistance

    std::vector<int> yourDistance(size, INF); // setting distances to infinty
    yourDistance[your_city] = 0;

    std::priority_queue<city_pair, std::vector<city_pair>, compare> queue;
    queue.push(std::make_pair(yourDistance[your_city], your_city));

    while (!queue.empty())
    {
        int curCity = queue.top().second;
        queue.pop();
        for (int i = 0; i < size; i++)
        {
            int distance = adj_matrix[curCity][i];
            if ((yourDistance[i] > yourDistance[curCity] + distance) and
                distance > 0)
            {
                yourDistance[i] = yourDistance[curCity] + distance;
                queue.push(std::make_pair(yourDistance[i], i));
            }
        }
    }
    
    // using Dijkstra's algorithm to find the shortest distance from 
    // friend_city to all cities in the graph and storing it in friendDistance

    std::vector<int> friendDistance(size, INF);
    friendDistance[friend_city] = 0;

    queue.push(std::make_pair(friendDistance[friend_city], friend_city));

    while (!queue.empty())
    {
        int curCity = queue.top().second;
        queue.pop();
        for (int i = 0; i < size; i++)
        {
            int distance = adj_matrix[curCity][i];
            if ((friendDistance[i] > friendDistance[curCity] + distance) and
                distance > 0)
            {
                friendDistance[i] = friendDistance[curCity] + distance;
                queue.push(std::make_pair(friendDistance[i], i));
            }
        }
    }

    int optimum = std::max(yourDistance[0], friendDistance[0]);
    int city = 0;

    for (int i = 1; i < size; i++)
    {
        int temp = std::max(yourDistance[i], friendDistance[i]);
        if (optimum > temp)
        {
            optimum = temp;
            city = i;
        }
    }

    return city;
}