//============================================================================
// Name        : MyWindow.
// Author      : Uros Stanic
// Date        : 11.01.2021
// Copyright   :
// Description : Definiton of the MyWindow class
//============================================================================

#pragma once

#define _USE_MATH_DEFINES

#include "Window.h"
#include "FL/Fl_Input.H"
#include "FL/Fl_File_Input.H"
#include "FL/Fl_Int_Input.H"
#include "GUI.h"
#include <cmath>
#include "Flight.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <regex>
#include "Sort.h"
#include "InputParmeters.h"

#define WINDOW_W			800
#define WINDOW_H			550
#define HOR_OFFSET			20
#define VER_OFFSET			20
#define BUTTON_W			100
#define BUTTON_H			20
#define X_AXIS_SIZE			(WINDOW_W-2*HOR_OFFSET)
#define Y_AXIS_SIZE			(WINDOW_H-2*VER_OFFSET)
#define X_SCALE				40
#define Y_SCALE				40
#define FILEINPUT_W			600
#define GENERAL_H_W			50
#define GENERAL_X			100

using namespace Graph_lib;

class MyWindow : public Window
{
public:
	MyWindow(Point xy, int w, int h, const string& title, bool cl);
	//handles button run calls sort, creates new window
	void quickSortRun(bool inside);
	//handles button run calls sort, creates new window
	void selectionSortRun(bool inside);
	//sets input parameters
	void setIp(InputParameters i);

private:
	vector<Flight> flights;
	InputParameters ip;

	Button selectionSortButton;
	Button quickSortButton;

	bool selectionPushed;
	bool quickPushed;

	//call back functions
	static void cbSelectionSort(Address, Address);
	static void cbQuickSort(Address, Address);
	//loads from imput file
	void loadFLights();
	//waits for button press
	void loopWindow();
	//creates parametetrs
	void createParameters();
	//writes to output file
	void generateOutput();

	In_box outputFileInput;
	In_box inputFileInput;

	In_box timePriorityTextBox;
	In_box destinationPriorityTextBox;
	In_box gateNumPriorityTextBox;
	In_box flightNumPriorityTextBox;
	In_box AscendingTextBox;
	~MyWindow() {};
};
