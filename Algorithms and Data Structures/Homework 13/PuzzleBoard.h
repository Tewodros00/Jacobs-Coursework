#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstdlib>
#include <ctime>

#define INF std::numeric_limits<int>::max()
#define puzzle_pair std::pair<int, int>

struct compare
{
    bool operator() (const puzzle_pair &city_one, const puzzle_pair &city_two) 
    {
        return city_one.second > city_two.second;
    }
};

class PuzzleBoard
{
private:
    int posX, posY;
    int boardSize;
    std::vector<std::vector<int>> fields;
    int graphSize;
    std::vector<std::vector<int>> graph; // adjacency matrix
    
public:
    PuzzleBoard(int boardSize,
       std::vector<std::vector<int>> fields = std::vector<std::vector<int>>());
    bool makeMove(int direction);
    bool getResult();
    friend std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m);
    int solve();
};

PuzzleBoard::PuzzleBoard(int boardSize, std::vector<std::vector<int>> fields)
{
    posX = posY = 0;
    this->boardSize = boardSize;
    
    srand(time(NULL));

    if (fields.empty())
    {
        fields.reserve(boardSize);
        for (int i = 0; i < boardSize; i++)
        {
            fields.emplace_back(boardSize, 0);
            for (int j = 0; j < boardSize; j++)
            {
                fields[i][j] = (rand() % (boardSize - 1)) + 1;
            }
        }  
    }
    this->fields = fields;

    graphSize = boardSize * boardSize;
    graph = std::vector<std::vector<int>>(graphSize, 
                std::vector<int>(graphSize, 0));

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            int dist = fields[i][j];
            
            if (i - dist > 0)
            {
                int row = i * boardSize + j;
                int col = (i - dist) * boardSize + j;
                graph[row][col] = 1;
            }

            if (i + dist < boardSize)
            {
                int row = i * boardSize + j;
                int col = (i + dist) * boardSize + j;
                graph[row][col] = 1;
            }

            if (j - dist > 0)
            {
                int row = i * boardSize + j;
                int col = i * boardSize + (j - dist);
                graph[row][col] = 1;
            }

            if (i + dist < boardSize)
            {
                int row = i * boardSize + j;
                int col = i * boardSize + (j + dist);
                graph[row][col] = 1;
            }
        }
    }
}


bool PuzzleBoard::makeMove(int direction)
{
    int distance = fields[posX][posY];

    if (direction == 0)
    {
        if (posX - distance > 0)
        {
            posX -= distance;
            return true;
        }
    }
    else if (direction == 1)
    {
        if (posY + distance < boardSize)
        {
            posY += distance;
            return true;
        }
    }
    else if (direction == 2)
    {
        if (posX + distance < boardSize)
        {
            posX += distance;
            return true;
        }
    }
    else if (direction == 3)
    {
        if (posY - distance > 0)
        {
            posY -= distance;
            return true;
        }
    }
    return false;
}

bool PuzzleBoard::getResult()
{
    if (posX == boardSize - 1 and posY == boardSize - 1)
    {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m)
{
    for (int i = 0; i < m.boardSize; i++)
    {
        for (int j = 0; j < m.boardSize; j++)
        {
            os << m.fields[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

int PuzzleBoard::solve()
{
    std::vector<int> distances(graphSize, INF);
    distances[0] = 0;

    std::priority_queue<puzzle_pair, std::vector<puzzle_pair>, compare> queue;
    queue.push(std::make_pair(distances[0], 0));

    while (!queue.empty())
    {
        int curPos = queue.top().second;
        queue.pop();
        for (int i = 0; i < graphSize; i++)
        {
            int distance = graph[curPos][i];
            if ((distances[i] > distances[curPos] + distance) and
                distance > 0)
            {
                distances[i] = distances[curPos] + distance;
                queue.push(std::make_pair(distances[i], i));
            }
        }
    }

    if (distances[graphSize - 1] == INF)
    {
        return -1;
    }
    return 1;
}