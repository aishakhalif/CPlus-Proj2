/**
 * @class StockSales
 * @brief Class to store and get the stock sales objects
 *
 *
 *
 * @author Aisha Khalif
 * @version 04
 *
 *
 */

#ifndef StockSales_H
#define StockSales_H

#include "date.h"
#include "time.h"
#include <string>

using namespace std;

//--------------------------------------------------

class StockSales
{

public:

    /**
     *@brief default constructor
     */
    StockSales();

    /**
     * @brief Standard constructor.
     * @param companyName, date, time, price, volume and value
     */
    StockSales(const Date& date, const Time& time, float price, int volume, float value);

    /**
     *@brief default destructor
     */
    ~StockSales();

    //-------------------------------------------------------------------------------------------

    /**
     *@brief returns the date for this stock sale
     *@return date object
     */
    Date getDate();

    //string getDateStr();

    /**
     *@brief returns the time for this stock sale
     *@return time object
     */
    Time getTime();

    /**
     *@brief returns price
     *@return price
     */
    float getPrice();

    /**
     *@brief returns value
     *@return value
     */
    float getValue();

    /**
     *@brief returns volume
     *@return volume
     */
    int getVolume();

    /**
     *@brief returns condition
     *@return condition
     */
    string getCondition();

    //-------------------------------------------------------------


    /**
     *@brief sets the name of the company for this stock sale
     *@param string s_companyName
     *@return void
     */
    void setCompanyName (string s_companyName);

    /**
     *@brief sets the date for this stock sale
     *@param s_date object passed by reference
     *@return void
     */
    void setDate (const Date & s_date);

    /**
     *@brief sets the time for this stock sale
     *@param s_time object passed by reference
     *@return void
     */
    void setTime(const Time & s_time);

    /**
     *@brief assigns price to sPrice
     *@param int sPrice
     *@return void
     */
    void setPrice(float sPrice);

    /**
     *@brief assigns value to sValue
     *@param int sValue
     *@return void
     */
    void setValue(float sValue);

    /**
     *@brief assigns volume to sVolume
     *@param int sVolume
     *@return void
     */
    void setVolume(int sVolume);

    /**
     *@brief assigns condition to sCondition
     *@param int sCondition
     *@return void
     */
    void setCondition(string sCondition);

    /**
     *@brief overloaded operator to output the vector content
     *@return param date and os
     */
    friend ostream & operator << (ostream & os, const StockSales & stock);


private:

    float price;
    float value;
    int volume;
    string condition;

    Date date;
    Time time;

};

#endif
