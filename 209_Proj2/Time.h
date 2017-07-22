/**
 * @class Time
 * @brief Class to store and get the time objects.
 *
 *
 *
 * @author Aisha Khalif
 * @version 04
 *
 *
 */

#ifndef Time_H
#define Time_H
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

//-------------------------------------------

class Time
{
public:

    /**
     *@brief default constructor
     */
    Time();

    /**
     * @brief Standard constructor.
     * @param hour, minute, second and ampm
     */
    Time(int hour, int minute, int second, char AMPM);

    /**
     *@brief default destructor
     */
    ~Time();

    /**
     *@brief returns hours
     *@return hour
     */
    int getHour();

    /**
     *@brief returns minutes
     *@return minute
     */
    int getMinute();

    /**
     *@brief returns seconds
     *@return second
     */
    int getSecond();

    /**
     *@brief returns time of date (AM or PM)
     *@return AMPM
     */
    char getAMPM();


//-----------------------------SETTERS--------------------


    /**
     *@brief assigns hour to tHour
     *@param int tHour
     */
    void setHour(int tHour);

    /**
     *@brief assigns minute to tMinute
     *@param int tMinute
     */
    void setMinute(int tMinute);

    /**
     *@brief assigns second to tSecond
     *@param int tSecond
     */
    void setSecond(int tSecond);

    /**
     *@brief assigns ampm to tAMPM
     *@param string tAMPM
     */
    void setAMPM(char tAMPM);


    /**
     *@brief overloaded operator to read in date
     *@return param date and is
     */
    friend istream & operator >> (istream & is, Time & time);

    /**
     *@brief overloaded operator to output the time
     *@return param date and os
     */
    friend ostream & operator << (ostream & os, const Time & time);


private:

    int hour;
    int minute;
    int second;
    char AMPM;
};

#endif // Time_H
