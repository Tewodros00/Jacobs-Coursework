#include <iostream>
#include <vector>
#include <stdexcept>

struct Activity
{
    int start, end;

    Activity(int start, int end)
    {
        if (end <= start or start < 0 or end < 0)
            throw std::invalid_argument("Error: Couldn't create Activity");
        this->start = start;
        this->end = end;
    }

    void print() const 
    {
        std::cout << "(" << start << ", " << end << ")";
    }
};

// compares activities based on their starting times
bool operator<(const Activity& a1, const Activity& a2);

// selects possible activities based on thier starting times
std::vector<Activity> selectActivities(std::vector<Activity> activities);

int main()
{
    std::vector<Activity> activityVector;
    activityVector.reserve(11);

    activityVector.emplace_back(1, 4);
    activityVector.emplace_back(3, 5);
    activityVector.emplace_back(0, 6);
    activityVector.emplace_back(5, 7);
    activityVector.emplace_back(3, 8);
    activityVector.emplace_back(5, 9);
    activityVector.emplace_back(6, 10);
    activityVector.emplace_back(8, 11);
    activityVector.emplace_back(8, 12);
    activityVector.emplace_back(2, 13);
    activityVector.emplace_back(12, 14);


    std::vector<Activity> result = selectActivities(activityVector);


    std::cout << "Possible activities: { ";
    for (unsigned int i = 0; i < result.size() - 1; i++)
    {
        result[i].print();
        std::cout << ", ";
    }
    result.back().print();
    std::cout << " }\n";
}


bool operator<(const Activity& a1, const Activity& a2)
{
    return a1.start < a2.start;
}

std::vector<Activity> selectActivities(std::vector<Activity> activities)
{
    std::vector<Activity> result;
    
    int ind = 0;
    // finds the index of the activity with the latest start time
    for (unsigned int i = 1; i < activities.size(); i++)
        if (activities[ind] < activities[i])
            ind = i;

    // adds the activity at the index to the result vector
    result.push_back(activities[ind]);
    // deletes the activity from the original vector
    activities.erase(activities.begin() + ind);
    
    while (activities.size() != 0)
    {
        ind = 0;
        // finds the index of the activity with the latest start time
        for (unsigned int i = 1; i < activities.size(); i++)
            if (activities[ind] < activities[i])
                ind = i;

        // adds the activity at the index to the result vector if it does not
        // overlap with the last item
        if (activities[ind].end <= result.back().start)
            result.push_back(activities[ind]);

        // deletes the activity from the original vector
        activities.erase(activities.begin() + ind);
    }
    
    return result;
}