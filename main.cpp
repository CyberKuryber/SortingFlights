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

//void loadFlights(ifstream& in);
//vector<Flight> flights;

//in sorthing out priority ascending
// sorting q s
// if shorter justo fill with x
//x skip

void main(int argc, char* argv[])
{
	cout << argv[1] << endl;
	if (argc == 1) {
		MainWindow mainWindow(Point(50, 50), WINDOW_W, WINDOW_H, "Sort Flights");
	}
	else if (argc < 3)
	{
		cout << "Invalid input, not enough command line arguments" << endl;
		return;
	}
	{
		MainWindow mainWindow(Point(50, 50), 0, 0, "Sort Flights");
		mainWindow.hide();
		mainWindow.loadFLights(argv[1]);
		char* priority[4];
		for (int i = 0; i < 4; i++)
		{
			priority[i] = "x";
		}
		for (int i = 4; i < argc && i<8; i++)
		{
			priority[i - 4] = argv[i];
		}

		char* ascending[4];
		for (int i = 0; i < 4; i++)
		{
			ascending[i] = "x";
		}
		for (int i = 8; i < argc && i<12; i++)
		{
			ascending[i - 8] = argv[i];
		}

		if (strcmp(argv[2],"q") == 0)
		{
			mainWindow.quickSortRun(false);
		}
		else if(strcmp(argv[2], "s") == 0)
		{
			mainWindow.selectionSortRun(false);
		}

		if (argc>4)
		{
			mainWindow.generateOutput(argv[3]);
		}
		else
		{
			mainWindow.generateOutput("");
		}
		

	}
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

/*void loadFlights(ifstream& in)
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
}*/