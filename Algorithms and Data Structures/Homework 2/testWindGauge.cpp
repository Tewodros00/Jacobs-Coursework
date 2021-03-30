/*
CH-231-A
hw2_p3.cpp
Tewodros Adane
tadane@jacobs-university.de
*/

#include <iostream>
#include "WindGauge.h"

int main(void) {
    WindGauge windGauge;

    windGauge.currentWindSpeed(15);
    windGauge.currentWindSpeed(16);
    windGauge.currentWindSpeed(12);
    windGauge.currentWindSpeed(15);
    windGauge.currentWindSpeed(15);

    windGauge.dump();
    std::cout << std::endl;
    
    windGauge.currentWindSpeed(16);
    windGauge.currentWindSpeed(17);
    windGauge.currentWindSpeed(16);
    windGauge.currentWindSpeed(16);
    windGauge.currentWindSpeed(20);
    windGauge.currentWindSpeed(17);
    windGauge.currentWindSpeed(16);
    windGauge.currentWindSpeed(15);
    windGauge.currentWindSpeed(16);
    windGauge.currentWindSpeed(20);

    windGauge.dump();

}