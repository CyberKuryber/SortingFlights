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
	static int sortingParameterArray[4];
	static int sortingParameter;
	static bool ascendingSort;

public:
	std::string getDepartureTime() const;
	std::string getGateNum() const;
	std::string getDestination() const;
	std::string getFlightNum() const;
	bool operator==(const Flight& flight);
	bool operator<(const Flight& flight);
	bool operator>(const Flight& flight);
	void setSortingParameter(int p,int pos) const;

};
