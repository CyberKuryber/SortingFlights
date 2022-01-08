#include "SortCounter.h"

void SortCounter::comparationCountInc() {
	this->comparationCount++;
}
void SortCounter::swapCountInc() {
	this->swapCount++;
}
void SortCounter::iterationCountInc() {
	this->iterationCount++;
	this->comparationsPerIteration.push_back(this->comparationCount);
	this->comparationCount = 0;
}

int SortCounter::getComparationCount() const {
	return this->comparationCount;
}
int SortCounter::getSwapCount() const {
	return this->swapCount;
}
int SortCounter::getIterationCount() const {
	return this->iterationCount;
}

SortCounter::SortCounter():swapCount(0),iterationCount(0),comparationCount(0) {}

std::vector<int> SortCounter::getComparationsPerIteration() {
	return this->comparationsPerIteration;
}
int SortCounter::getTotalComparationCount() {
	std::vector<int>::iterator it;
	int total = 0;
	for ( it = this->comparationsPerIteration.begin(); it != this->comparationsPerIteration.end(); it++)
	{
		total += (*it);
	}
	return total;
}
