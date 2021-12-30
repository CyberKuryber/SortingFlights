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

int Flight::sortingParameter = 3;
int Flight::sortingParameterArray[4] = { 3,2,1,0 };
bool Flight::ascendingSort[4] = { false,false,false,false };
Flight::Flight(std::string gate, std::string dest, std::string flight, std::string time) :gateNum(gate), destination(dest), flightNum(flight), departureTime(time) {}

std::string Flight::getGateNum() const {
	return this->gateNum;
}
std::string Flight::getDepartureTime() const {
	return this->departureTime;
}
std::string Flight::getDestination() const {
	return this->destination;
}
std::string Flight::getFlightNum() const{
	return this->flightNum;
}

bool Flight::operator==(const Flight& flight) {
	switch (Flight::sortingParameter)
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
	switch (Flight::sortingParameter)
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
	switch (Flight::sortingParameter)
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

std::string Flight::toString() {
	return this->destination + ";" + this->departureTime + ";" + this->flightNum + ";" + this->gateNum;
}