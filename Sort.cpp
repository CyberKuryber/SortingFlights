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

void SelectionSort::primarySort(std::vector<Flight>& data, bool sortOrder, DrawingWindow& dw) {
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
			dw.addElements(data);
			dw.drawOuts();
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
	if (Flight::sortingParameter == -1)
	{
		return;
	}

	DrawingWindow dw(Point(50, 50), WINDOW_W, WINDOW_H, "Drawing");

	this->primarySort(data, Flight::ascendingSort[0], dw);

	for (int i = 1; i < sizeof(Flight::sortingParameterArray) / sizeof(Flight::sortingParameterArray[0]); i++)
	{
		std::vector<std::vector<Flight>> toSort;
		std::vector<Flight> current;
		for (int j = 0; j < data.size() - 1; j++)
		{
			current.push_back(data[j]);
			if (!(data[j] == data[j + 1])) {
				toSort.push_back(current);
				current.clear();
			}
		}
		if (!current.empty())
		{
			toSort.push_back(current);
		}
		if (toSort[toSort.size() - 1][0] == data[data.size() - 1])
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
			if (toSort[j].size() > 1)
				primarySort(toSort[j], Flight::ascendingSort[i], dw);
			for (int k = 0; k < toSort[j].size(); k++)
			{
				data[dataCounter] = toSort[j][k];
				dataCounter++;
			}
		}

		dw.loopWindow();
		current.clear();
		toSort.clear();
	}
}

//Merge Sort

std::vector<Flight> MergeSort::findLeft(std::vector<Flight>& data, int mid) {
	std::vector<Flight> left;
	for (int i = 0; i < mid; i++)
	{
		left.push_back(data[i]);
	}
	return left;
}

std::vector<Flight> MergeSort::findRight(std::vector<Flight>& data, int mid) {
	std::vector<Flight> right;
	for (int i = mid; i < data.size(); i++)
	{
		right.push_back(data[i]);
	}
	return right;
}

std::vector<Flight> MergeSort::merge(std::vector<Flight>& left, std::vector<Flight>& right, bool sortOrder) {
	std::vector<Flight> data;
	int	i = 0;
	int	j = 0;

	while (i < left.size() && j < right.size()) {
		if (sortOrder)
		{
			if (left[i] < right[j]) {
				data.push_back(left[i]);
				i += 1;
			}
			else {
				data.push_back(right[j]);
				j += 1;
			}
		}
		else
		{
			if (left[i] > right[j]) {
				data.push_back(left[i]);
				i += 1;
			}
			else {
				data.push_back(right[j]);
				j += 1;
			}
		}
	}
	if (i < left.size()) {
		while (i < left.size())
		{
			data.push_back(left[i]);
			i += 1;
		}
	}
	if (j < right.size()) {
		while (j < right.size())
		{
			data.push_back(right[j]);
			j += 1;
		}
	}
	return data;
}

std::vector<Flight> MergeSort::primarySort(std::vector<Flight>& data, bool sortOrder, DrawingWindow& dw) {
	int n = data.size();
	if (n == 1)return data;

	int	mid = n / 2;
	std::vector<Flight> left = this->findLeft(data, mid);
	std::vector<Flight> right = this->findRight(data, mid);
	dw.addElements(left);
	dw.drawOuts();
	dw.generateGap();
	dw.addElements(right);
	dw.drawOuts();
	left = primarySort(left, sortOrder, dw);
	right = primarySort(right, sortOrder, dw);

	return merge(left, right, sortOrder);
}

void MergeSort::sort(std::vector<Flight>& data) {
	this->resetNumCmps();
	Flight::sortingParameter = Flight::sortingParameterArray[0];
	if (Flight::sortingParameter == -1)
	{
		return;
	}
	DrawingWindow dw(Point(50, 50), WINDOW_W, WINDOW_H, "Drawing");

	data = this->primarySort(data, Flight::ascendingSort[0], dw);

	for (int i = 1; i < sizeof(Flight::sortingParameterArray) / sizeof(Flight::sortingParameterArray[0]); i++)
	{
		std::vector<std::vector<Flight>> toSort;
		std::vector<Flight> current;
		for (int j = 0; j < data.size() - 1; j++)
		{
			current.push_back(data[j]);
			if (!(data[j] == data[j + 1])) {
				toSort.push_back(current);
				current.clear();
			}
		}
		if (!current.empty())
		{
			toSort.push_back(current);
		}
		if (toSort[toSort.size() - 1][0] == data[data.size() - 1])
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
			if (toSort[j].size() > 1)
				toSort[j] = primarySort(toSort[j], Flight::ascendingSort[i], dw);
			for (int k = 0; k < toSort[j].size(); k++)
			{
				data[dataCounter] = toSort[j][k];
				dataCounter++;
			}
		}

		dw.loopWindow();
		current.clear();
		toSort.clear();
	}
}