//============================================================================
// Name        : Sort.h
// Author      : 
// Date        :
// Copyright   : 
// Description : Sort interface class and various sorting algorithms in C++
//============================================================================
#pragma once

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
	virtual void primarySort(std::vector<Flight>& data, bool sortOrder) = 0;
};

// SelectionSort class
class SelectionSort : public Sort
{
public:
	// main entry point
	void sort(std::vector<Flight>& data);
	void primarySort(std::vector<Flight>& data, bool sortOrder);
};

