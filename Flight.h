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
	time_t departureTime;

public:
	time_t getDepartureTime() const;
	std::string getGateNum() const;
	std::string getDestination() const;
	std::string getFlightNum() const;
	bool operator==(const Flight& flight);
	bool operator<(const Flight& flight);
	bool operator>(const Flight& flight);
};
