#include "MainWindow.h"


//TODO Radio button ako me ne bude mrzelo
MainWindow::MainWindow(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	selectionSortButton(
		Point(GENERAL_X,9*GENERAL_H_W),
		BUTTON_W,
		BUTTON_H,
		"Selection Sort",
		cb_selectionSort),
	mergeSortButton(
		Point(GENERAL_H_W + GENERAL_H_W*5, 9 * GENERAL_H_W),
		BUTTON_W,
		BUTTON_H,
		"Merge Sort",
		cb_mergeSort),
	inputFileInput(
		Point(GENERAL_X,GENERAL_H_W),
		FILEINPUT_W,
		GENERAL_H_W,
		"Input File Path"
	),
	outputFileInput(
		Point(GENERAL_X,GENERAL_H_W * 3),
		FILEINPUT_W,
		GENERAL_H_W,
		"Output File Path"
	),
	gateNumPriorityTextBox(
		Point(GENERAL_X,GENERAL_H_W * 5),
		GENERAL_H_W,
		GENERAL_H_W,
		"Gate Priority"
	),
	flightNumPriorityTextBox(
		Point(GENERAL_X + 4 * GENERAL_H_W,
		GENERAL_H_W * 5),
		GENERAL_H_W,
		GENERAL_H_W,
		"Flight Priority"
	),
	destinationPriorityTextBox(
		Point(GENERAL_X + 8 * GENERAL_H_W,GENERAL_H_W * 5),
		GENERAL_H_W,
		GENERAL_H_W,
		"Flight Priority"
	),

	timePriorityTextBox(
		Point(GENERAL_X + 12 * GENERAL_H_W,GENERAL_H_W * 5),
		GENERAL_H_W,
		GENERAL_H_W,
		"Time Priority"
	),
	gateNumAscendingTextBox(
		Point(GENERAL_X,GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Gate Priority"
	),
	flightNumAscendingTextBox(
		Point(GENERAL_X + 4 * GENERAL_H_W,GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Flight Ascending"
	),
	destinationAscendingTextBox(
		Point(GENERAL_X + 8 * GENERAL_H_W,GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Flight Ascending"
	),

	timeAscendingTextBox(
		Point(GENERAL_X + 12 * GENERAL_H_W,GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Time Ascending"
	),
	mergePushed(false),
	selectionPushed(false)

{
	attach(selectionSortButton);
	attach(mergeSortButton);
	attach( outputFileInput);
	attach(inputFileInput);
	attach(timePriorityTextBox);
	attach(timeAscendingTextBox);
	attach(destinationPriorityTextBox);
	attach(destinationAscendingTextBox);
	attach(gateNumPriorityTextBox);
	attach(gateNumAscendingTextBox);
	attach(flightNumPriorityTextBox);
	attach(flightNumAscendingTextBox);

	loopWindow();
}


void MainWindow::cb_selectionSort(Address, Address pw)
{
	reference_to<MainWindow>(pw).selectionSortRun();
}

void MainWindow::cb_mergeSort(Address, Address pw)
{
	reference_to<MainWindow>(pw).mergeSortRun();
}

void MainWindow::loadFLights() {

//TODO citaj posle sranja
	//ifstream in("../inputFileExample.txt");
	if (!in)
	{
		std::cerr << "ERROR: wrong input file name!";
		exit(-1);
	}

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

void MainWindow::selectionSortRun() {
	loadFLights();
	SelectionSort ss = SelectionSort();
	ss.resetNumCmps();
	ss.sort(flights);
}

void MainWindow::mergeSortRun() {
	loadFLights();
	MergeSort ms = MergeSort();
	ms.sort(flights);
}

void MainWindow::loopWindow() {
	show();
	while (true)
	{
		while (!selectionPushed && !mergePushed) Fl::wait();
		
		if (selectionPushed)
		{
			selectionSortRun();
		}
		else {
			mergeSortRun();
		}

	}

}