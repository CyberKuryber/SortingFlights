//============================================================================
// Name        : Flight.h
// Author      :
// Date        :
// Copyright   :
// Description :
//============================================================================
#pragma once
#include <string>

class Flight
{
private:
	std::string gateNum;
	std::string destination;
	std::string flightNum;
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
	static bool ascendingSort[4];
	std::string toString();
};
