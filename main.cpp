//============================================================================
// Name        : main.cpp
// Author      :
// Date        :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <regex>
#include "Flight.h"
#include "Sort.h"
#include "MainWindow.h"

using namespace std;

void loadFlights(ifstream& in);
vector<Flight> flights;



void main()
{
	MainWindow mainWindow(Point(50, 50),WINDOW_W, WINDOW_H,"Sort Flights");
	

	/*ifstream in("../inputFileExample.txt");
	if (!in)
	{
		cerr << "ERROR: wrong input file name!";
		exit(-1);
	}

	loadFlights(in);
	
	
	/*SelectionSort ss = SelectionSort();
	ss.sort(flights);
	MergeSort ms = MergeSort();
	ms.sort(flights);*/
	cout << "WTF" << endl;

}

void loadFlights(ifstream& in)
{
	string line;
	getline(in, line);
	while (!in.eof())
	{
		int id;
		string name;
		string surname;

		string line;
		getline(in, line);
		vector<string> tokens;
		size_t pos = 0;
		string delimiter = ";";
		string token;


		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			token = std::regex_replace(token, std::regex("\\i"), "");
			tokens.push_back(token);
			line.erase(0, pos + delimiter.length());

		}
		
		

		flights.push_back(Flight(tokens[3], tokens[0], tokens[2], tokens[1]));

	}
}
