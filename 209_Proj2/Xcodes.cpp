/**
* @class Xcodes.cpp
* @brief Implementation of Xcodes.cpp
*
*
*
* @author Aisha Khalif
* @version 04
*
*
*/

#include "Xcodes.h"

Xcodes::Xcodes() {


}

Xcodes::~Xcodes() {

}

//---------------------------------------------------------------------------------

string Xcodes::getCompanyName() {
	return companyName;
}

void Xcodes::setCompanyName(string x_CompanyName) {
	companyName = x_CompanyName;
}

string Xcodes::getSaleName() {
	return saleName;
}

void Xcodes::setSaleName(string x_SaleName) {
	saleName = x_SaleName;
}

//---------------------------------------------------------------------------------

void Xcodes::fillXcodeVec()
{
	string line;
	Xcodes xcodes;
	StockSales sales;

	//read in the code_index with the company names
	ifstream inFile("x-codes\\code_index.txt");

	if (!inFile)
	{
		cout << "Code Index File Not Found!\n";
		inFile.close();
	}

	else
	{

		//read in the relevant data
		while (getline(inFile, line))
		{
			xcodes.setCompanyName(line);

			vec_codeIndex.push_back(xcodes);
		}

		//for every company in the code_index, open and read it's sales_index
		for (unsigned int i = 0; i < vec_codeIndex.size(); i++)
		{
			string companyFileName = vec_codeIndex[i].getCompanyName();



			ifstream inFile(("x-codes\\" + companyFileName + "\\Sales_index.txt").c_str());

			if (!inFile.is_open())
			{
				cout << "File not found!";
				inFile.close();
			}

			else
			{

				//read in the relevant data
				while (getline(inFile, line))
				{
					//cout << line << endl;

					xcodes.setSaleName(line);
					vec_saleIndex.push_back(xcodes);
				}
			}


			for (unsigned int i = 0; i < vec_saleIndex.size(); i++)
			{
				string saleFileName = vec_saleIndex[i].getSaleName();
				string line;


				ifstream inFile(("x-codes\\" + companyFileName + "\\" + saleFileName).c_str());

				if (!inFile.is_open())
				{
					cout << "Sales index file not found!\n";
					inFile.close();
				}

				else
				{
					//first skip the first 2 lines
					getline(inFile, line);
					getline(inFile, line);

					//get the rest of the data
					while (!inFile.eof())
					{
						//cout << endl;

						inFile >> date;
						sales.setDate(date);
						//cout << date << "\n";

						inFile >> time;
						sales.setTime(time);
						//cout << time << "\n";

						//PRICE, VOLUME AND VALUE
						getline(inFile, line, ',');
						sales.setPrice(atof(line.c_str()));
						//cout << "Price = " << line << endl; //- For unit testing purposes
						getline(inFile, line, ',');
						sales.setVolume(atoi(line.c_str()));
						//cout << "Volume = " << line << endl; //- For unit testing purposes

						getline(inFile, line, ',');
						sales.setValue(atof(line.c_str()));
						//cout << "Value = " << line << endl; //- For unit testing purposes

						//ignore CONDITION field and go to new line.
						getline(inFile, line);
						sales.setCondition(line);
						//cout << "Condition = " <<line << endl; //- For unit testing purposes

						vec_shares.push_back(sales);


					}

				}

			}

			vec_saleIndex.clear(); //clear the vector with the sale day file names
			map_shareInfo.insert(pair< string, vector <StockSales> >(companyFileName, vec_shares));
			//maybe push that vector into the the BST at this point? before I clear it?
			vec_shares.clear();


		}
	}

}



//--------------------------------------------------------------------------------------------------------------

void Xcodes::companyMenu() {

	Xcodes xcodesObj;
	string choice;

	cout << "Enter the name of the company you want work with, or enter Q to exit the program" << endl;

	for (unsigned int i = 0; i < vec_codeIndex.size(); i++)
	{
		cout << i + 1 << ": " << vec_codeIndex[i].getCompanyName() << endl;
	}

	cin >> choice;

	if (choice != "Q" && choice != "q")
	{
		salesDatesMenu(choice);
	}

	else
	{
		exit(0);
	}
}

void Xcodes::salesDatesMenu(string &choice) {


	map<string, vector<StockSales> >::const_iterator it = map_shareInfo.find(choice);
	if (it != map_shareInfo.end())
	{
		cout << "\nStock Code: " << it->first << endl << "Dates: " << endl;

		vector <StockSales> map_shareInfo = (*it).second;
		for (unsigned j = 0; j < map_shareInfo.size(); j++)
		{
			//if ()
			cout << map_shareInfo[j].getDate() << endl;
			BSTPriceSort.insert(map_shareInfo[j].getPrice());
		}

	}
	else
	{
		cout << "\nPlease only enter one of the companies offered. Please note that the program is case sensitive.\n" << endl;
		companyMenu();
	}

	cout << "Enter the date you want work with, or enter Q to exit and R to return to previous menu" << endl;

	do {

        cin.clear(); //clear it of it's previous value
		cin >> choice;


        size_t found = choice.find('/');
        if (found != std::string::npos)
        {
            mainMenu();
        }

        if (choice == "R" || choice == "r")
		{
			companyMenu();
		}

        else
		{
			cout << "\nPlease only enter one of the dates offered and in the format shown above or R to return and Q to quit. \n" << endl;
		}



		//one check to see if user input is really one of the dates offered, if it is, show the, menu

	} while (choice != "q" && choice != "Q");

}

void Xcodes::mainMenu()
{
	int option;

	do {

		cout << endl
			<< "1: Find the highest share price times" << endl
			<< "2: Find the lowest share price times" << endl
			<< "3: Find price change and output data into a new file" << endl
			<< "4: Return to the initial menu" << endl
			<< "5: Quit" << endl;

		cin >> option;

		cout << endl;

		switch (option)
		{
		case 1:
			highestPriceShare();
			break;

		case 2:
			lowestPriceShare();
			break;

		case 3:
			break;

		case 4:
			companyMenu();
			break;

		case 5:
		    exit(0);
			break;


		default: cout << option << " is not a valid option. Please only enter a number between 1 and 5" << endl;
			cout << endl;
		}


	} while (option != 5);
}


void Xcodes::highestPriceShare()
{
	double price = BSTPriceSort.return_highestPrice();
	Date highestPriceDate;
	Time highestPriceTime;

	typedef map<string, vector<StockSales> >::const_iterator MapIterator;
	for (MapIterator iter = map_shareInfo.begin(); iter != map_shareInfo.end(); iter++)
	{
		vector <StockSales> map_shareInfo = (*iter).second;
		for (unsigned j = 0; j < map_shareInfo.size(); j++)
		{
			if (map_shareInfo[j].getPrice() == price)
			{
				highestPriceDate = map_shareInfo[j].getDate();
				highestPriceTime = map_shareInfo[j].getTime();
			}
		}
	}

	cout << "Stock Code: " << endl;
	cout << "Date: " << highestPriceDate << endl;
	cout << "Highest Price: " << price << endl;
	cout << "Start Time(s): " << highestPriceTime << endl;

}

void Xcodes::lowestPriceShare()
{
	double price = BSTPriceSort.return_lowestPrice();
	Date lowestPriceDate;
	Time lowestPriceTime;

	typedef map<string, vector<StockSales> >::const_iterator MapIterator;
	for (MapIterator iter = map_shareInfo.begin(); iter != map_shareInfo.end(); iter++)
	{
		vector <StockSales> map_shareInfo = (*iter).second;
		for (unsigned j = 0; j < map_shareInfo.size(); j++)
		{
			if (map_shareInfo[j].getPrice() == price)
			{
				lowestPriceDate = map_shareInfo[j].getDate();
				lowestPriceTime = map_shareInfo[j].getTime();
			}
		}
	}

	cout << "Stock Code: " << endl;
	cout << "Date: " << lowestPriceDate << endl;
	cout << "Lowest Price: " << price << endl;
	cout << "Start Time(s): " << lowestPriceTime << endl;


}
