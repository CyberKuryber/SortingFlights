//============================================================================
// Name        : Sort.cpp
// Author      :
// Date        :
// Copyright   :
// Description : Implementation of the sort classes
//============================================================================

#include "Sort.h"
using namespace std;

unsigned long Sort::getNumCmps() {
	return this->num_cmps;
}

void Sort::resetNumCmps() {
	this->num_cmps = 0;
}

void SelectionSort::primarySort(std::vector<Flight>& data, bool sortOrder, DrawingWindow& dw, SortCounter& sortCounter) {
	Flight::sortingParameter = Flight::sortingParameterArray[0];
	if (sortOrder)
	{
		for (int i = 0; i < data.size() - 1; i++) {
			Flight min = data[i];
			int minIndex = i;
			for (int j = i + 1; j < data.size(); j++)
			{
				if (min > data[j])
				{
					sortCounter.swapCountInc();
					min = data[j];
					minIndex = j;
				}
				sortCounter.comparationCountInc();
			}
			Flight hlp = data[i];
			data[i] = min;
			data[minIndex] = hlp;

			sortCounter.iterationCountInc();
			dw.addIterLable(sortCounter.getIterationCount());
			dw.addElements(data);
			dw.drawOuts();
			dw.newRow();
			
		}
	}
	else
	{
		for (int i = 0; i < data.size() - 1; i++) {
			for (int i = 0; i < data.size() - 1; i++) {
				Flight max = data[i];
				int maxIndex = i;
				for (int j = i + 1; j < data.size(); j++)
				{
					if (max < data[j])
					{
						max = data[j];
						maxIndex = j;
						sortCounter.swapCountInc();
					}
					sortCounter.comparationCountInc();
				}
				Flight hlp = data[i];
				data[i] = max;
				data[maxIndex] = hlp;

				sortCounter.iterationCountInc();
				dw.addIterLable(sortCounter.getIterationCount());
				dw.addElements(data);
				dw.drawOuts();
				dw.newRow();
			}
			
		}

	}
}

void SelectionSort::sort(std::vector<Flight>& data) {
	this->resetNumCmps();
	SortCounter sortcounter;
	Flight::sortingParameter = Flight::sortingParameterArray[0];
	if (Flight::sortingParameter == -1)
	{
		return;
	}

	DrawingWindow dw(Point(50, 50), WINDOW_W, WINDOW_H, "Drawing");

	this->primarySort(data, Flight::ascendingSort, dw, sortcounter);

		dw.addCustomTextLabel("Finish:");
		dw.addElements(data);
		dw.drawOuts();
		

		dw.newRow();
		int iterationCount = sortcounter.getIterationCount();
		sortcounter.iterationCountInc();
		int total = sortcounter.getTotalComparationCount();
		int swapCount = sortcounter.getSwapCount();
		dw.addCustomTextLabel("Iterations:");
		dw.addIterLable(iterationCount);
		dw.addCustomTextLabel("Swaps:");
		dw.addIterLable(swapCount);
		dw.addCustomTextLabel("Comparations:");
		dw.addIterLable(total);
		dw.drawOuts();
		dw.loopWindow();

	
}


void QuickSort::sort(std::vector<Flight>& data) {
	SortCounter sortCounter;
	this->resetNumCmps();
	Flight::sortingParameter = Flight::sortingParameterArray[0];
	if (Flight::sortingParameter == -1)
	{
		return;
	}

	DrawingWindow dw(Point(50, 50), WINDOW_W, WINDOW_H, "Drawing");

	this->primarySort(data, Flight::ascendingSort, 0, data.size() - 1, dw, sortCounter);

	

	dw.addCustomTextLabel("Finish:");
	dw.addElements(data);
	dw.drawOuts();
	
	
	dw.newRow();
	int iterationCount = sortCounter.getIterationCount();
	sortCounter.iterationCountInc();
	int total = sortCounter.getTotalComparationCount();
	int swapCount = sortCounter.getSwapCount();
	dw.addCustomTextLabel("Iterations:");
	dw.addIterLable(iterationCount);
	dw.addCustomTextLabel("Swaps:");
	dw.addIterLable(swapCount);
	dw.addCustomTextLabel("Comparations:");
	dw.addIterLable(total);
	dw.drawOuts();

	dw.loopWindow();
}

void swap(Flight* a, Flight* b)
{
	Flight t = *a;
	*a = *b;
	*b = t;
}

void QuickSort::primarySort(std::vector<Flight>& data, bool sortOrder, int first, int last, DrawingWindow& dw, SortCounter& sortCounter) {
	if (first < (last))
	{
		int index = this->rpartition(data, sortOrder, first, last, sortCounter);

		sortCounter.iterationCountInc();
		dw.addIterLable(sortCounter.getIterationCount());
		dw.addElements(data);
		dw.drawOuts();
		dw.newRow();
		primarySort(data, sortOrder, first, index, dw, sortCounter);
		primarySort(data, sortOrder, index + 1, last, dw, sortCounter);
	}
}

int  QuickSort::partition(std::vector<Flight>& data, bool sortOrder, int first,int last, SortCounter& sortCounter) {
	Flight pivot = data[last];

	int i = first - 1;

	for (int j = first; j < last; j++)
	{
		if (sortOrder)
		{
			if (data[j] < pivot)
			{
				i++;
				swap(data[i], data[j]);
				sortCounter.swapCountInc();
			}
		}
		else {
			if (data[j] > pivot)
			{
				i++;
				swap(data[i], data[j]);
				sortCounter.swapCountInc();
			}
		}
		sortCounter.comparationCountInc();
	}

	swap(data[++i], data[last]);
	sortCounter.swapCountInc();

	return i;
}

int  QuickSort::rpartition(std::vector<Flight>& data, bool sortOrder, int first, int last, SortCounter& sortCounter) {
	srand(time(NULL));
	int i = rand();
	i = first + (i % (last - first));
	swap(data[i], data[last]);
	return this->partition(data, sortOrder, first, last,sortCounter);
}