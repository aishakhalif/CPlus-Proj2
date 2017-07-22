/**
 * @class Date
 * @brief Class to store and get the date and time objects.
 *
 *
 * @author Aisha Khalif
 * @version 04
 *
 *
 */


#ifndef Date_h
#define Date_h
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
//-------------------------------------------

class Date
{
public:

    /**
     *@brief default constructor
     */
    Date();

    /**
     * @brief Standard constructor.
     * @param day, month and year
     */
    Date(int day, int month, int year);

    /**
     *@brief default destructor
     */
    ~Date();

    //---------------------------------GETTERS--------------------------------
    /**
     *@brief returns the date as the initial string from file
     *@return string date
     */
    string getStringDate();

    /**
     *@brief returns day
     *@return day
     */
    int getDay();

    /**
     *@brief returns month
     *@return month
     */
    int getMonth();

    /**
     *@brief returns year
     *@return year
     */
    int getYear();


    //---------------------------------SETTERS--------------------------------
    /**
     *@brief assigns string date to dateString
     *@param string dateString
     *@return void
     */
    void setStringDate(string dateString);

    /**
     *@brief assigns day to dDay
     *@param int dDay
     *@return void
     */
    void setDay(int dDay);

    /**
     *@brief assigns month to dMonth);
     *@param int dMonth);
     *@return void
     */
    void setMonth(int dMonth);

    /**
     *@brief assigns year to dYear
     *@param int dYear
     *@return void
     */
    void setYear(int dYear);

    /**
     *@brief overloaded operator to read in date
     *@return param date and is
     */
    friend istream & operator >> (istream & is, Date & date);

    /**
     *@brief overloaded operator to output the date
     *@return param date and os
     */
    friend ostream & operator << (ostream & os, const Date & date);



private:

    // attributes
    string stringDate;

    int day;
    int month;
    int year;
};

#endif // DATETIME_H
