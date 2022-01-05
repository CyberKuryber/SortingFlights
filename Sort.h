//============================================================================
// Name        : Sort.h
// Author      :
// Date        :
// Copyright   :
// Description : Sort interface class and various sorting algorithms in C++
//============================================================================
#pragma once

#include "DrawingWindow.h"
#include "Flight.h"
#include <vector>

// Sort class
class Sort
{
protected:
	// number of comparisons performed in sort function
	unsigned long num_cmps;
public:
	// main entry point
	virtual void sort(std::vector<Flight>& data) = 0;
	// returns number of comparisons
	unsigned long getNumCmps();
	// resets the number of comparisons
	void resetNumCmps();
	//virtual void primarySort(std::vector<Flight>& data, bool sortOrder) = 0;
};

// SelectionSort class
class SelectionSort : public Sort
{
public:
	// main entry point
	void sort(std::vector<Flight>& data);
	void primarySort(std::vector<Flight>& data, bool sortOrder, DrawingWindow& dw);
};

class QuickSort : public Sort
{
public:
	void sort(std::vector<Flight>& data);
	void primarySort(std::vector<Flight>& data, bool sortOrder, int first, int last, DrawingWindow& dw);
	int partition(std::vector<Flight>& data, int first, int last);
	int rpartition(std::vector<Flight>& data, int first, int last);

};

/*
class MergeSort : public Sort {
public:
	void sort(std::vector<Flight>& data);
	std::vector<Flight> primarySort(std::vector<Flight>& data, bool sortOrder, DrawingWindow& dw);
	std::vector<Flight> merge(std::vector<Flight>& left, std::vector<Flight>& right, bool sortOrder);
	std::vector<Flight> findLeft(std::vector<Flight>& data, int mid);
	std::vector<Flight> findRight(std::vector<Flight>& data, int mid);
};*/

