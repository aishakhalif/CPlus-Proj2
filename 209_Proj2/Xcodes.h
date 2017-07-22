/**
 * @class Xcodes
 * @brief Class to navigate through folder and read in data, store them in data structures and use them to carry out menu functions
 *
 *
 *
 * @author Aisha Khalif
 * @version 04
 *
 *
 */

#ifndef Xcodes_hpp
#define Xcodes_hpp

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "BST.h"
#include "StockSales.h"
#include "date.h"
#include "time.h"

using namespace std;

class Xcodes
{

public:

    /**
     *@brief default constructor
     */
    Xcodes();

    /**
     *@brief default destructor
     */
    ~Xcodes();

    /**
     *@brief returns comapny file name
     *@return company file name
     */
    string getCompanyName();

    /**
     *@brief returns sales file name
     *@return sales file name
     */
    string getSaleName();

    /**
     *@brief assigns company name to x_ComapnyName
     *@param string x_Company
     *@return void
     */
    void setCompanyName(string x_CompanyName);

    /**
     *@brief assigns company name to x_ComapnyName
     *@param string x_Company
     *@return void
     */
    void setSaleName(string x_SaleName);

    /**
     *@brief fills a vector with the company names retrieved from code_index.txt
     *@return void
     */
    void fillXcodeVec();

    /**
     *@brief displays a menu of the company (folder) names to user
     *@return void
     */
    void companyMenu();

    /**
     *@brief displays a menu of the sales dates to user
     *@return void
     */
    void salesDatesMenu(string &choice);

    /**
     *@brief function to find information on the highest price share
     *@return void
     */
    void highestPriceShare();

    /**
     *@brief function to find information on the lowest price share
     *@return void
     */
    void lowestPriceShare();

    /**
     *@brief displays a main menu to user
     *@return void
     */
    void mainMenu();

private:


    string companyName;
    string saleName;

    vector <Xcodes> vec_codeIndex;
    vector <Xcodes> vec_saleIndex;
    vector <StockSales> vec_shares;

    //BST <StockSales> BSTPriceSort;
    BST <float> BSTPriceSort;
    map < string, vector<StockSales> > map_shareInfo;

    //A map of string, 3D Vector pair
    //map < string, vector < vector < vector <StockSales> > > > map_shareInformation; //a map of share information so <CBA, DAY<SHARE INFO>>

    Time time;
    Date date;
};

#endif /* Xcodes_hpp */
