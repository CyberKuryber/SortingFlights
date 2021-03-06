//============================================================================
// Name        : SortCounter.h
// Author      : Uros Stanic
// Date        : 11.01.2022.
// Copyright   :
// Description : DrawingWindow class implementation
//============================================================================

#include "DrawingWindow.h"

/*
0 gateNum
1 flightNum
2 destination
3 time*/
void DrawingWindow::addElements(vector<Flight>& f) {
	vector<Flight>::iterator it;

	for (it = f.begin(); it != f.end(); it++)
	{
		string s;
		switch (Flight::sortingParameter)
		{
		case 0: {
			s = (*it).getFlightNum();
			break;
		}
		case 1: {
			s = (*it).getFlightNum();
			break;
		}
		case 2: {
			s = (*it).getDestination();
			break;
		}

		default:
			s = (*it).getDepartureTime();
			break;
		}
		//Out_box current(Point(currentX, currentY), 0, GENERAL_H, f[i].getFlightNum());
		this->outs.push_back(new Out_box(Point(currentX, currentY), 0, GENERAL_H, s));
		this->currentX += GENERAL_X;
	}
	while (!this->isNextButtonPushed() && !this->exitButtonPushed)
	{
		Fl::wait();
	}
	if (this->exitButtonPushed)
	{
		exit(0);
	}
}

void DrawingWindow::newRow() {
	this->currentX = GENERAL_X;
	this->currentY += GENERAL_H;
}

void DrawingWindow::drawOuts() {
	for (int i = 0; i < this->outs.size(); i++)
	{
		this->attach(*(this->outs[i]));
	}

	this->outs.clear();

	this->redraw();
	this->nextButtonPushed = false;
}

DrawingWindow::DrawingWindow(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	currentX(GENERAL_X),
	currentY(GENERAL_H),
	exitButtonPushed(false),
	nextButtonPushed(false),
	exitButton(
		Point(0, 0),
		BUTTON_W,
		BUTTON_H,
		"Exit",
		cb_exit),
	nextButton(
		Point(BUTTON_W, 0),
		BUTTON_W,
		BUTTON_H,
		"Next",
		cb_next)
{
	attach(exitButton);
	attach(nextButton);
}

void DrawingWindow::cb_exit(Address, Address pw)
{
	reference_to<DrawingWindow>(pw).exitButtonRun();
}

void DrawingWindow::exitButtonRun() {
	exitButtonPushed = true;
}

void DrawingWindow::cb_next(Address, Address pw)
{
	reference_to<DrawingWindow>(pw).nextButtonRun();
}

void DrawingWindow::nextButtonRun() {
	nextButtonPushed = true;
}

void DrawingWindow::loopWindow() {
	while (!this->exitButtonPushed)
	{
		Fl::wait();
	}
}

void DrawingWindow::generateGap() {
	this->outs.push_back(new Out_box(Point(currentX, currentY), 0, GENERAL_H, "\t|"));
	this->drawOuts();
}

bool DrawingWindow::isNextButtonPushed() {
	return this->nextButtonPushed;
}

void DrawingWindow::addIterLable(int x) {
	stringstream ss;
	ss << x;
	this->outs.push_back(new Out_box(Point(currentX, currentY), 0, GENERAL_H, ss.str()));
	this->currentX += GENERAL_X;
}
void DrawingWindow::addCustomTextLabel(std::string text) {
	this->outs.push_back(new Out_box(Point(currentX, currentY), 0, GENERAL_H, text));
	this->currentX += GENERAL_X;
}