//============================================================================
// Name        : SortCounter.h
// Author      : Uros Stanic
// Date        : 11.01.2022.
// Copyright   :
// Description : SortCounter collects data during sort
//============================================================================

#pragma once
#include<string>
#include<map>
#include<vector>

class SortCounter
{
public:
	// Increments parameters
	void comparationCountInc();
	void swapCountInc();
	void iterationCountInc();

	//getters and setters
	int getComparationCount() const;
	int getSwapCount() const;
	int getIterationCount() const;
	std::vector<int> getComparationsPerIteration();
	int getTotalComparationCount();

	SortCounter();
	~SortCounter() {};

private:
	int comparationCount;
	int swapCount;
	int iterationCount;
	std::map<int, int> mapCurrentSwaps;
	std::vector<std::map<int, int>> ChangesList;
	std::vector<int> comparationsPerIteration;
};
