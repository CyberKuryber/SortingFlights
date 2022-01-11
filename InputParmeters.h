//============================================================================
// Name        : InputParameters.h
// Author      : Uros Stanic
// Date        : 11.01.2022.
// Copyright   :
// Description : handles input parameters
//============================================================================

#pragma once
#include <string>
#include <iostream>
#include <vector>

class InputParameters {
private:
	std::string inputFilePath;
	std::string outputFilePath;
	bool isSelectionSort;

public:
	InputParameters();
	//gewnerates parameters from command line
	void commandGenerate(int argc, char* argv[]);
	//genereates parameters from gui
	void guiGenerate(std::vector<std::string> argv);
	//setters and getters
	void setSortType(std::string s);
	bool getIsSelectionSort() const;
	std::string getInputFilePath() const;
	std::string getOutputFilePath() const;
	void setInputFilePath(std::string s);
	void setOutputFilePath(std::string s);
	~InputParameters() {};
};