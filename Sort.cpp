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


void SelectionSort::primarySort(std::vector<Flight>& data,bool sortOrder) {
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
					min = data[j];
					minIndex = j;
				}
				this->num_cmps++;
			}
			Flight hlp = data[i];
			data[i] = min;
			data[minIndex] = hlp;

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
					}
					this->num_cmps++;
				}
				Flight hlp = data[i];
				data[i] = max;
				data[maxIndex] = hlp;

			}
			

		}
	}

}

void SelectionSort::sort(std::vector<Flight>& data) {
	
	this->resetNumCmps();
	Flight::sortingParameter = Flight::sortingParameterArray[0];
	if (Flight::sortingParameter==-1)
	{
		return;
	}

	
	this->primarySort(data,Flight::ascendingSort[0]);

	

	for (int i = 1; i < sizeof(Flight::sortingParameterArray) / sizeof(Flight::sortingParameterArray[0]); i++)
	{
		
		std::vector<std::vector<Flight>> toSort;
		std::vector<Flight> current;
		for (int j = 0; j < data.size()-1; j++)
		{
			current.push_back(data[j]);
			if (!(data[j] == data[j+1])) {
				toSort.push_back(current);
				current.clear();
			}
		}
		if (!current.empty())
		{
			toSort.push_back(current);
		}
		if (toSort[toSort.size()-1][0] == data[data.size() - 1])
		{
			toSort[toSort.size() - 1].push_back(data[data.size() - 1]);
		}
		else
		{
			current.push_back(data[data.size() - 1]);
			
		}
		Flight::sortingParameter = Flight::sortingParameterArray[i];
		int dataCounter = 0; 
		for (int j = 0; j < toSort.size(); j++) {
			if(toSort[j].size()>1)
			primarySort(toSort[j],Flight::ascendingSort[i]);
			for (int k = 0; k < toSort[j].size(); k++)
			{
				data[dataCounter] = toSort[j][k];
				dataCounter++;

			}
		}

		
		//TODO vizuelizacija
		current.clear();
		toSort.clear();
	}

}