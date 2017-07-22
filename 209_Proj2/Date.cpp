/**
 * @class Date
 * @brief Implementation of the Date.h file.
 *
 *
 *
 * @author Aisha Khalif
 * @version 04
 *
 *
 */

#include "Date.h"

Date::Date() {
    day = 0;
    month = 0;
    year = 0000;
}

// Standard constructor
Date::Date(int day, int month, int year)
{

    setDay(day);
    setMonth(month);
    setYear(year);
}

Date::~Date() {
}

//-------------------------------------------

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

//-------------------------------------------

void Date::setDay(int dDay) {
    day = dDay;
}

void Date::setMonth(int dMonth) {
    month = dMonth;
}

void Date::setYear(int dYear) {
    year = dYear;
}


istream & operator >> (istream & is, Date & date)

{
    char slash;
    is >> date.day >> slash >> date.month >> slash >> date.year;
    return is;
}

ostream & operator << (ostream & os, const Date & date)

{
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}


