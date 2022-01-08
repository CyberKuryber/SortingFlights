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

class MainWindow : public Window
{
public:
	MainWindow(Point xy, int w, int h, const string& title, bool cl);
	void loadFLights(string path);
	void quickSortRun(bool inside);
	void selectionSortRun(bool inside);
	void createParameters(char* pr[], char* asc[]);
	void generateOutput(string path);
	void setIp(InputParameters i);

private:
	vector<Flight> flights;
	InputParameters ip;

	Button selectionSortButton;
	Button quickSortButton;

	bool selectionPushed;
	bool quickPushed;

	static void cb_selectionSort(Address, Address);
	static void cb_quickSort(Address, Address);
	void loadFLights();
	void loopWindow();
	void createParameters();
	void generateOutput();

	In_box outputFileInput;
	In_box inputFileInput;

	In_box timePriorityTextBox;
	In_box destinationPriorityTextBox;
	In_box gateNumPriorityTextBox;
	In_box flightNumPriorityTextBox;
	In_box AscendingTextBox;
};
