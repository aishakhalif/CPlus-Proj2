/**
 * @class Time
 * @brief Implementation of the Time.h class
 *
 *
 *
 * @author Aisha Khalif
 * @version 04
 *
 *
 */

#include "Time.h"


//-----------------------------------------------

/**
 * constructor and destructor
 */

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
    AMPM = 'P';
}

//standard constructor
Time::Time(int hour, int minute, int second, char AMPM)
{

    setHour(hour);
    setMinute(minute);
    setSecond(second);
    setAMPM(AMPM);
}

Time::~Time(void) {
}

//-------------------------------------------

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}

char Time::getAMPM() {
    return AMPM;
}

//-------------------------------------------

void Time::setHour(int tHour) {
    hour = tHour;
}

void Time::setMinute(int tMinute) {
    minute = tMinute;
}

void Time::setSecond(int tSecond) {
    second = tSecond;
}

void Time::setAMPM(char tAMPM) {
    AMPM = tAMPM;
}

istream & operator >> (istream & is, Time & time)

{
    char colon;
    char skip;
    is >> time.hour >> colon >> time.minute >> colon >> time.second >> time.AMPM >> skip >> skip; //skips the M in PM/AM and the colon before the price

    return is;
}

ostream & operator << (ostream & os, const Time & time)
{

    os << time.hour << ":" << time.minute << ":"  << time.second << " " << time.AMPM;
    return os;
}
