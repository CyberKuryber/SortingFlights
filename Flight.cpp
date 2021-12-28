//============================================================================
// Name        : Flight.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of the Flight class
//============================================================================

#include "Flight.h"
/*
0 gateNum
1 flightNum
2 destination
3 time*/


std::string Flight::getGateNum() const {
	return this->gateNum;

}
std::string Flight::getDepartureTime() const {
	return this->departureTime;
}
std::string Flight::getDestination() const {
	return this->destination;
}
std::string Flight::getFlightNum() const {
	return this->flightNum;
}

bool Flight::operator==(const Flight& flight) {
	switch (this->sortingParameter)
	{
	case 0: {
		return (this->gateNum.compare(flight.getGateNum()) == 0);
	}
	case 1: {
		return (this->flightNum.compare(flight.getFlightNum()) == 0);
	}
	case 2: {
		return (this->destination.compare(flight.getDestination()) == 0);
	}
	default: {
		return (this->departureTime.compare(flight.getDepartureTime()) == 0);
	}
	}
}

bool Flight::operator<(const Flight& flight) {
	switch (this->sortingParameter)
	{
	case 0: {
		return (this->gateNum.compare(flight.getGateNum()) < 0);
	}
	case 1: {
		return (this->flightNum.compare(flight.getFlightNum()) < 0);
	}
	case 2: {
		return (this->destination.compare(flight.getDestination()) < 0);
		
	}
	default: {
		return (this->departureTime.compare(flight.getDepartureTime()) < 0);
		}
	}
}

bool Flight::operator>(const Flight& flight) {
	switch (this->sortingParameter)
	{
	case 0: {
		return (this->gateNum.compare(flight.getGateNum()) > 0);
	}
	case 1: {
		return (this->flightNum.compare(flight.getFlightNum()) > 0);
	}
	case 2: {
		return (this->destination.compare(flight.getDestination()) > 0);

	}
	default: {
		return (this->departureTime.compare(flight.getDepartureTime()) > 0);
	}
	}
}

void Flight::setSortingParameter(int p, int pos) const {
	if (pos<0 || pos>3)
	{
		return;
	}
	this->sortingParameterArray[pos] = p;
}