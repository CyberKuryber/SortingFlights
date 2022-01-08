#include "InputParmeters.h"
#include "MainWindow.h"


InputParameters::InputParameters() : isSelectionSort(true),inputFilePath(""), outputFilePath("") {}

void InputParameters::commandGenerate(int argc, char* argv[]) {
	inputFilePath = argv[1];
	char* pr[4];
	for (int i = 0; i < 4; i++)
	{
		pr[i] = "x";
	}
	for (int i = 4; i < argc && i < 8; i++)
	{
		pr[i - 4] = argv[i];
	}


	

	vector<std::string> priority;
	bool ascending;
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


	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++) {
			if (priority[i].compare(priority[j]) > 0)
			{
				std::string pom = priority[j];
				priority[j] = priority[i];
				priority[i] = pom;

				int pomI = codedPriority[j];
				codedPriority[j] = codedPriority[i];
				codedPriority[i] = pomI;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		Flight::sortingParameterArray[i] = codedPriority[i];
	}
	if (argc>3)
	{
		outputFilePath = argv[3];
	}
	this->setSortType(argv[2]);
	
	if (argc == 9)
	{
		Flight::ascendingSort = !(strcmp(argv[8], "false") == 0);
	}

}

void InputParameters::guiGenerate(vector<std::string> argv) {
	vector<std::string> priority;
	bool ascending;
	vector<int> codedPriority;
	for (int i = 0; i < 4; i++)
	{
		priority.push_back(argv[i]);
		codedPriority.push_back(i);
	}



	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++) {
			if (priority[i].compare(priority[j]) > 0)
			{
				std::string pom = priority[j];
				priority[j] = priority[i];
				priority[i] = pom;

				int pomI = codedPriority[j];
				codedPriority[j] = codedPriority[i];
				codedPriority[i] = pomI;
			}
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		Flight::sortingParameterArray[i] = codedPriority[i];
	}
	Flight::ascendingSort = !(argv[4].compare("false") == 0);
}

void InputParameters::setSortType(std::string s){

	isSelectionSort = (s.compare("q") != 0);

}

bool InputParameters::getIsSelectionSort() const {
	return this->isSelectionSort;
}

std::string InputParameters::getInputFilePath() const {
	return inputFilePath;
}
std::string InputParameters::getOutputFilePath() const {
	return outputFilePath;
}
void InputParameters::setInputFilePath(std::string s) {
	inputFilePath = s;
}
void InputParameters::setOutputFilePath(std::string s) {
	outputFilePath = s;
}