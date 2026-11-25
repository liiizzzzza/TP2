#pragma once

#pragma once

#include <iostream>
#include <string>

using namespace std;

class AEROFLOT
{
private:
    string destination;
    int flightNumber;
    string aircraftType;

public:
    
    AEROFLOT();

    AEROFLOT(string destination, int flightNumber, string aircraftType);

    AEROFLOT(const AEROFLOT& other);

    ~AEROFLOT();

    void setDestination(string destination);
    void setFlightNumber(int flightNumber);
    void setAircraftType(string aircraftType);

    string getDestination() const;
    int getFlightNumber() const;
    string getAircraftType() const;

    friend istream& operator>>(istream& in, AEROFLOT& flight);
    friend ostream& operator<<(ostream& out, const AEROFLOT& flight);

    AEROFLOT& operator=(const AEROFLOT& other);
};
