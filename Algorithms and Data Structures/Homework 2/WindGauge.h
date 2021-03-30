/*
CH-231-A
hw2_p3.h
Tewodros Adane
tadane@jacobs-university.de
*/

#include <deque>

class WindGauge {
    private:
        std::deque<int> windSpeeds;
        int period; 
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const; 
        void dump() const;  
};