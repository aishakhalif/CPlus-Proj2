#include "Xcodes.h"

/*

void Test1();
void Test2();
void Test3();

int main() {

    //Test1();
    //Test2();
    Test3();
}

void Test1() {

    vector <Xcodes> vec_codeIndex;
    string line;
	Xcodes xcodes;

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

		cout << "\nSIZE: " << vec_codeIndex.size() << "\n";

		for (int i = 0; i < vec_codeIndex.size(); i++){

            cout << "\n" << vec_codeIndex[i].getCompanyName();
        }
	}
}

void Test2() {

            vector <Xcodes> vec_saleIndex;
            string line;
            Xcodes xcodes;

        	ifstream inFile("x-codes\\IAG\\Sales_index.txt");

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

                cout << "\nSIZE: " << vec_saleIndex.size() << "\n";

                for (int i = 0; i < vec_saleIndex.size(); i++){

                    cout << "\n" << vec_saleIndex[i].getSaleName();
                }
        }
}

void Test3() {

            vector <StockSales> vec_shares;
            map < string, vector<StockSales> > map_shareInfo;

            string line;
            Date date;
            Time time;
            StockSales sales;

                ifstream inFile("x-codes\\IAG\\day1.csv");

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

						getline(inFile, line);
						sales.setCondition(line);
						//cout << "Condition = " <<line << endl; //- For unit testing purposes

						vec_shares.push_back(sales);


					}

				//cout << "\nSIZE: " << vec_shares.size() << "\n";

                //for (int i = 0; i < vec_shares.size(); i++){

                    //cout << "\n" << vec_shares[i];
                //}

                //cout << endl;

        }

                map_shareInfo.insert(pair< string, vector <StockSales> >("IAG", vec_shares));


                typedef map<string, vector<StockSales> >::const_iterator MapIterator;
                for (MapIterator iter = map_shareInfo.begin(); iter != map_shareInfo.end(); iter++)
                {
                   cout << "\nKey: " << iter->first << endl << "Values: " << endl;

                    vector <StockSales> vec_shares = (*iter).second;
                    for (unsigned j = 0; j < vec_shares.size(); j++)
                    {
                        cout << vec_shares[j] << endl;
                    }
                }
}



*/
