#include "MainWindow.h"


//TODO Radio button ako me ne bude mrzelo
MainWindow::MainWindow(Point xy, int w, int h, const string& title,bool cl) :
	Window(xy, w, h, title),
	selectionSortButton(
		Point(GENERAL_X, 9 * GENERAL_H_W),
		BUTTON_W,
		BUTTON_H,
		"Selection Sort",
		cb_selectionSort),
	quickSortButton(
		Point(GENERAL_H_W + GENERAL_H_W * 5, 9 * GENERAL_H_W),
		BUTTON_W,
		BUTTON_H,
		"Quick Sort",
		cb_quickSort),
	inputFileInput(
		Point(GENERAL_X, GENERAL_H_W),
		FILEINPUT_W,
		GENERAL_H_W,
		"Input File Path"
	),
	outputFileInput(
		Point(GENERAL_X, GENERAL_H_W * 3),
		FILEINPUT_W,
		GENERAL_H_W,
		"Output File Path"
	),
	gateNumPriorityTextBox(
		Point(GENERAL_X, GENERAL_H_W * 5),
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
		Point(GENERAL_X + 8 * GENERAL_H_W, GENERAL_H_W * 5),
		GENERAL_H_W,
		GENERAL_H_W,
		"Destination Priority"
	),

	timePriorityTextBox(
		Point(GENERAL_X + 12 * GENERAL_H_W, GENERAL_H_W * 5),
		GENERAL_H_W,
		GENERAL_H_W,
		"Time Priority"
	),
	AscendingTextBox(
		Point(GENERAL_X, GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Ascending"
	),
	quickPushed(false),
	selectionPushed(false)

{
	attach(selectionSortButton);
	attach(quickSortButton);
	attach(outputFileInput);
	attach(inputFileInput);
	attach(timePriorityTextBox);
	attach(destinationPriorityTextBox);
	attach(gateNumPriorityTextBox);
	attach(flightNumPriorityTextBox);
	attach(AscendingTextBox);

	if (!cl)
	{
		loopWindow();
	}
	
}

void MainWindow::cb_selectionSort(Address, Address pw)
{
	reference_to<MainWindow>(pw).selectionSortRun(true);
}

void MainWindow::cb_quickSort(Address, Address pw)
{
	reference_to<MainWindow>(pw).quickSortRun(true);
}


void MainWindow::loadFLights() {
	//TODO citaj posle sranja
	ifstream in(this->ip.getInputFilePath());
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
	in.close();
}

void MainWindow::selectionSortRun(bool inside) {
	if (inside) {
		createParameters();
	}

	loadFLights();
	SelectionSort ss = SelectionSort();
	ss.resetNumCmps();
	ss.sort(flights);
	this->generateOutput();
	//selectionPushed = true;
}

void MainWindow::quickSortRun(bool inside) {
	if (inside)
	{
		createParameters();
	}
	flights.clear();
	loadFLights();
	QuickSort qs = QuickSort();
	qs.sort(flights);

	this->generateOutput();
	//quickPushed = true;
}

void MainWindow::loopWindow() {
	show();
	while (true)
	{
		while (!selectionPushed && !quickPushed) Fl::wait();

		if (selectionPushed)
		{
			selectionSortRun(true);
		}
		else {
			quickSortRun(true);
		}
	}
}

/*
0 gateNum
1 flightNum
2 destination
3 time
../inputFileExample.txt s ../outputFileExample.txt 1 1 1 0
*/

void MainWindow::createParameters() {

	vector<std::string> args;
	char* argv[8];

	args.push_back(gateNumPriorityTextBox.get_string());
	args.push_back(flightNumPriorityTextBox.get_string());
	args.push_back(destinationPriorityTextBox.get_string());
	args.push_back(timePriorityTextBox.get_string());
	args.push_back(AscendingTextBox.get_string());

	ip.setInputFilePath(inputFileInput.get_string());
	ip.setOutputFilePath(outputFileInput.get_string());
	ip.guiGenerate(args);
	
}

void MainWindow::generateOutput() {
	if (ip.getOutputFilePath().empty())
	{
		return;
	}

	ofstream out(ip.getOutputFilePath());
	vector<Flight>::iterator it;
	for (it = flights.begin(); it != flights.end(); it++)
	{
		out << (*it).toString() << endl;
	}
	out.close();
}

void MainWindow::setIp(InputParameters i) {
	this->ip = i;
}