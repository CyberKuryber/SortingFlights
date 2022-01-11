//============================================================================
// Name        : Flight.h
// Author      :
// Date        :
// Copyright   :
// Description : Main class for defining window
//============================================================================
#pragma once
#include <string>

class Flight
{
private:
	std::string gateNum;
	std::string destination;

	std::string departureTime;

public:
	Flight(std::string gate, std::string dest, std::string flight, std::string time);
	std::string getDepartureTime() const;
	std::string getGateNum() const;
	std::string getDestination() const;
	std::string getFlightNum() const;
	bool operator==(const Flight& flight);
	bool operator<(const Flight& flight);
	bool operator>(const Flight& flight);
	static int sortingParameterArray[4];
	static int sortingParameter;
	static bool ascendingSort;
	std::string toString();
	std::string flightNum;
	~Flight() {};
};
