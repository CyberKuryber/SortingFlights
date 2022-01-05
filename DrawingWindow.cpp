#include "DrawingWindow.h"

void DrawingWindow::addElements(vector<Flight>& f) {
	vector<Flight>::iterator it;

	for (int i = 0; i < f.size(); i++)
	{

		//Out_box current(Point(currentX, currentY), 0, GENERAL_H, f[i].getFlightNum());
		this->outs.push_back(new Out_box(Point(currentX, currentY), 0, GENERAL_H, f[i].getFlightNum()));
		this->currentX += GENERAL_X;
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
}

DrawingWindow::DrawingWindow(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	currentX(GENERAL_X),
	currentY(GENERAL_H)
	{
	}

void DrawingWindow::generateGap() {
	this->outs.push_back(new Out_box(Point(currentX, currentY), 0, GENERAL_H, "\t|"));
	this->drawOuts();
}

void DrawingWindow::loopWindow() {
	while (true)
	{
		Fl::wait();
	}
}