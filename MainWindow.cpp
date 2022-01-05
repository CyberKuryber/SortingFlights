#include "MainWindow.h"

//TODO Radio button ako me ne bude mrzelo
MainWindow::MainWindow(Point xy, int w, int h, const string& title) :
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
	gateNumAscendingTextBox(
		Point(GENERAL_X, GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Gate Ascending"
	),
	flightNumAscendingTextBox(
		Point(GENERAL_X + 4 * GENERAL_H_W, GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Flight Ascending"
	),
	destinationAscendingTextBox(
		Point(GENERAL_X + 8 * GENERAL_H_W, GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Destination Ascending"
	),

	timeAscendingTextBox(
		Point(GENERAL_X + 12 * GENERAL_H_W, GENERAL_H_W * 7),
		GENERAL_H_W,
		GENERAL_H_W,
		"Time Ascending"
	),
	quickPushed(false),
	selectionPushed(false)

{
	attach(selectionSortButton);
	attach(quickSortButton);
	attach(outputFileInput);
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
	reference_to<MainWindow>(pw).selectionSortRun(true);
}

void MainWindow::cb_quickSort(Address, Address pw)
{
	reference_to<MainWindow>(pw).quickSortRun(true);
}

void MainWindow::loadFLights(string path) {
	ifstream in(path);
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

void MainWindow::loadFLights() {
	//TODO citaj posle sranja
	ifstream in(inputFileInput.get_string());
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
		loadFLights();
	}

	SelectionSort ss = SelectionSort();
	ss.resetNumCmps();
	ss.sort(flights);
	if (inside)
	{
		this->generateOutput();
	}
}

void MainWindow::quickSortRun(bool inside) {
	if (inside)
	{
		createParameters();
		loadFLights();
	}

	QuickSort qs = QuickSort();
	qs.sort(flights);

	if (inside) {
		this->generateOutput();
	}
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
3 time*/

void MainWindow::createParameters() {
	vector<std::string> priority;
	vector<bool> ascending;
	vector<int> codedPriority;
	if (gateNumPriorityTextBox.get_string().empty())
	{
		priority.push_back("1");
	}
	else
	{
		priority.push_back(gateNumPriorityTextBox.get_string());
	}
	if (flightNumPriorityTextBox.get_string().empty())
	{
		priority.push_back("1");
	}
	else
	{
		priority.push_back(flightNumPriorityTextBox.get_string());
	}

	if (destinationPriorityTextBox.get_string().empty())
	{
		priority.push_back("1");
	}
	else
	{
		priority.push_back(destinationPriorityTextBox.get_string());
	}

	if (timePriorityTextBox.get_string().empty())
	{
		priority.push_back("0");
	}
	else
	{
		priority.push_back(timePriorityTextBox.get_string());
	}

	for (int i = 0; i < 4; i++)
	{
		codedPriority.push_back(i);
	}

	if (gateNumAscendingTextBox.get_string().compare("false") == 0)
	{
		ascending.push_back(false);
	}
	else
	{
		ascending.push_back(true);
	}

	if (flightNumAscendingTextBox.get_string().compare("false") == 0)
	{
		ascending.push_back(false);
	}
	else
	{
		ascending.push_back(true);
	}
	if (destinationAscendingTextBox.get_string().compare("false") == 0)
	{
		ascending.push_back(false);
	}
	else
	{
		ascending.push_back(true);
	}
	if (timeAscendingTextBox.get_string().compare("false") == 0)
	{
		ascending.push_back(false);
	}
	else
	{
		ascending.push_back(true);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++) {
			if (priority[i].compare(priority[j]) > 0)
			{
				std::string pom = priority[j];
				priority[j] = priority[i];
				priority[i] = pom;

				bool pomB = ascending[j];
				ascending[j] = ascending[i];
				ascending[i] = pomB;

				int pomI = codedPriority[j];
				codedPriority[j] = codedPriority[i];
				codedPriority[i] = pomI;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		Flight::ascendingSort[i] = ascending[i];
		Flight::sortingParameterArray[i] = codedPriority[i];
	}
}

void MainWindow::createParameters(char* pr[], char* asc[]) {
	vector<std::string> priority;
	vector<bool> ascending;
	vector<int> codedPriority;
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(pr[i], "x") == 0)
		{
			priority.push_back("x");
		}
		else
		{
			priority.push_back(pr[i]);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		codedPriority.push_back(i);
	}

	for (int i = 0; i < 4; i++)
	{
		if (strcmp(asc[i], "false") == 0)
		{
			ascending.push_back(false);
		}
		else
		{
			ascending.push_back(true);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++) {
			if (priority[i].compare(priority[j]) > 0)
			{
				std::string pom = priority[j];
				priority[j] = priority[i];
				priority[i] = pom;

				bool pomB = ascending[j];
				ascending[j] = ascending[i];
				ascending[i] = pomB;

				int pomI = codedPriority[j];
				codedPriority[j] = codedPriority[i];
				codedPriority[i] = pomI;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		Flight::ascendingSort[i] = ascending[i];
		Flight::sortingParameterArray[i] = codedPriority[i];
	}
}

void MainWindow::generateOutput(string path) {
	if (path.empty())
	{
		return;
	}

	ofstream out(path);
	vector<Flight>::iterator it;
	for (it = flights.begin(); it != flights.end(); it++)
	{
		out << (*it).toString() << endl;
	}
	out.close();
}

void MainWindow::generateOutput() {
	if (outputFileInput.get_string().empty())
	{
		return;
	}

	ofstream out(outputFileInput.get_string());
	vector<Flight>::iterator it;
	for (it = flights.begin(); it != flights.end(); it++)
	{
		out << (*it).toString() << endl;
	}
	out.close();
}