#ifndef TASK0302_TIME_H
#define TASK0302_TIME_H

#include <iostream>

class Time
{
private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;

public:
    Time();
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds);
    Time(const Time& time);

    unsigned int getHours() const;
    void setHours(unsigned int hours);
    unsigned int getMinutes() const;
    void setMinutes(unsigned int minutes);
    unsigned int getSeconds() const;
    void setSeconds(unsigned int seconds);

    unsigned int toSeconds() const;

    std::string toString() const;
    
    bool operator<(const Time& other) const
    {
        return this->toSeconds() < other.toSeconds();
    }

    // Dodatek: Operator za primerjavo več kot
    bool operator>(const Time& other) const
    {
        return this->toSeconds() > other.toSeconds();
    }
};

#endif  // TASK0302_TIME_H
