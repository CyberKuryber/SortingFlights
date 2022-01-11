//============================================================================
// Name        : DrawingWindow.h
// Author      : Uros Stanic
// Date        : 11.01.2022.
// Copyright   :
// Description : DrawingWindow class definiton, it is window for visualisation
//============================================================================
#pragma once

#define _USE_MATH_DEFINES

#include "Window.h"
#include "GUI.h"
#include "Flight.h"
#include <vector>
#include <iostream>
#include "FL/Fl_Output.H"

#define WINDOW_W			1200
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
#define GENERAL_H			25
#define GENERAL_W			50
#define GENERAL_X			100

using namespace Graph_lib;

class DrawingWindow : public Window
{
public:
	DrawingWindow(Point xy, int w, int h, const string& title);
	//creates labels from flight vector
	void addElements(vector<Flight>& f);
	void generateGap();
	//draws generated labels
	void drawOuts();
	//waits for button press
	void loopWindow();
	//creates new row for lables
	void newRow();
	//getter
	bool isNextButtonPushed();
	//creates label with int value
	void addIterLable(int x);
	//creates label with custom string
	void addCustomTextLabel(std::string text);
	~DrawingWindow() {};

private:
	int currentX;
	int currentY;
	bool exitButtonPushed;
	bool nextButtonPushed;
	vector<Out_box*>  outs;
	Button exitButton;
	Button nextButton;
	static void cb_exit(Address, Address);
	void exitButtonRun();
	static void cb_next(Address, Address);
	void nextButtonRun();
};
