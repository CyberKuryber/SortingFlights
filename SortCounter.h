#pragma once
#include<string>
#include<map>
#include<vector>

class SortCounter
{
public:
	void comparationCountInc();
	void swapCountInc();
	void iterationCountInc();

	int getComparationCount() const;
	int getSwapCount() const;
	int getIterationCount() const;
	SortCounter();

private:
	int comparationCount;
	int swapCount;
	int iterationCount;
	std::map<int, int> mapCurrentSwaps;
	std::vector<std::map<int, int>> ChangesList;
};
