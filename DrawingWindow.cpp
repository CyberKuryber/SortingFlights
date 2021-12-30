#include "DrawingWindow.h"

void DrawingWindow::addElements(vector<Flight>& f) {
	vector<Flight>::iterator it;

	for (it = f.begin(); it != f.end(); it++)
	{
		string s = (*it).getFlightNum();
		Button current(Point(currentX, currentY), GENERAL_W, GENERAL_H, s.c_str(), NULL);
		this->attach(current);
		this->currentX += GENERAL_W;
	}
	this->currentX = GENERAL_X;
	this->currentY += GENERAL_H;
}

DrawingWindow::DrawingWindow(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	currentX(GENERAL_X),
	currentY(GENERAL_H)
	{
	}

void DrawingWindow::generateGap() {
	this->currentY += GENERAL_H;
}

void DrawingWindow::loopWindow() {
	while (true)
	{
		Fl::wait();
	}
}