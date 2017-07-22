/**
 * @class StockSales
 * @brief Implementation of the StockSales.h file.
 *
 *
 *
 * @author Aisha Khalif
 * @version 03
 * @date
 *
 *
 */

#include "StockSales.h"
#include <iostream>

//----------------------------------------------

//default constructor
StockSales::StockSales()
{
    date = Date();
    time = Time();
    price = 0.00;
    volume = 0;
    value = 0.00;
}

//standard constructor
StockSales::StockSales(const Date & date, const Time & time, float price, int volume, float value)
{
    //setDate(date);
    //setTime(time); //not necessary
    setPrice(price);
    setVolume(volume);
    setValue(value);
}

//default destructor
StockSales::~StockSales(){
}


//------------------------------------------

Date StockSales::getDate()
{
    return date;
}

Time StockSales::getTime()
{
    return time;
}

float StockSales::getPrice()
{
    return price;
}

float StockSales::getValue()
{
    return value;
}

int StockSales::getVolume()
{
    return volume;
}

string StockSales::getCondition()
{
    return condition;
}

//----------------------------------------------------

void StockSales::setDate(const Date & s_date)
{
    date = s_date;
}

void StockSales::setTime(const Time & s_time)
{
    time = s_time;
}

void StockSales::setPrice(float sPrice)
{
    price = sPrice;
}

void StockSales::setValue(float sValue)
{
    value = sValue;
}

void StockSales::setVolume(int sVolume)
{
    volume = sVolume;
}

void StockSales::setCondition(string sCondition)
{
    condition = sCondition;
}

ostream & operator << (ostream & os, const StockSales & stock)
{

    os << stock.date << "," << stock.time << ","  << stock.price << "," << stock.value << "," << stock.volume << "," << stock.condition;
    return os;
}
