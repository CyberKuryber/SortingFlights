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
	void commandGenerate(int argc, char* argv[]);
	void guiGenerate(std::vector<std::string> argv);
	void setSortType(std::string s);
	bool getIsSelectionSort() const;
	std::string getInputFilePath() const;
	std::string getOutputFilePath() const;
	void setInputFilePath(std::string s);
	void setOutputFilePath(std::string s);
};