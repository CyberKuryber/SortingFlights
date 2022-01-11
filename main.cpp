//============================================================================
// Name        : main.cpp
// Author      :Uros Stanic
// Date        :11.01.2022.
// Copyright   :
// Description :main program start
//============================================================================

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <regex>
#include "Flight.h"
#include "Sort.h"
#include "MyWindow.h"

using namespace std;

//void loadFlights(ifstream& in);
//vector<Flight> flights;

//in sorthing out priority ascending
// sorting q s
// if shorter justo fill with x
//x skip

void main(int argc, char* argv[])
{
	if (argc == 1) {
		MyWindow mainWindow(Point(50, 50), WINDOW_W, WINDOW_H, "Sort Flights", false);
	}
	else if (argc < 3)
	{
		cout << "Invalid input, not enough command line arguments" << endl;
		return;
	}
	else {
		MyWindow mainWindow(Point(50, 50), WINDOW_W, WINDOW_H, "Sort Flights", true);
		InputParameters ip;
		ip.commandGenerate(argc, argv);
		mainWindow.setIp(ip);

		if (ip.getIsSelectionSort())
		{
			mainWindow.selectionSortRun(false);
		}
		else
		{
			mainWindow.quickSortRun(false);
		}
	}
}