/*
CH-231-A
hw2_p3.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include <algorithm>
#include "WindGauge.h"

WindGauge::WindGauge(int period) {
    this->period = period;
}

void WindGauge::currentWindSpeed(int speed) {
    windSpeeds.push_front(speed);
    if ((int) windSpeeds.size() > period)
        windSpeeds.pop_back();
}

int WindGauge::highest() const {
    return *std::max_element(windSpeeds.begin(), windSpeeds.end());
}

int WindGauge::lowest() const {
    return *std::min_element(windSpeeds.begin(), windSpeeds.end());
}

int WindGauge::average() const {
    int sum = 0;
    for (int speed : windSpeeds)
        sum += speed;
    return sum / windSpeeds.size();
}

void WindGauge::dump() const {
    std::cout << "Highest: " << this->highest() << std::endl;
    std::cout << "Lowest:  " << this->lowest()  << std::endl;
    std::cout << "Average: " << this->average() << std::endl;
}

