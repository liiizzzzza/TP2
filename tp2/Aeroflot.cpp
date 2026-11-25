#include "Aeroflot.h"

AEROFLOT::AEROFLOT()
{
    destination = "";
    flightNumber = 0;
    aircraftType = "";

    cout << "Вызван конструктор без параметров AEROFLOT" << endl;
}

AEROFLOT::AEROFLOT(string destination, int flightNumber, string aircraftType)
{
    this->destination = destination;
    this->flightNumber = flightNumber;
    this->aircraftType = aircraftType;

    cout << "Вызван конструктор с параметрами AEROFLOT" << endl;
}

AEROFLOT::AEROFLOT(const AEROFLOT& other)
{
    destination = other.destination;
    flightNumber = other.flightNumber;
    aircraftType = other.aircraftType;

    cout << "Вызван конструктор копирования AEROFLOT" << endl;
}

AEROFLOT::~AEROFLOT()
{
    cout << "Вызван деструктор AEROFLOT: " << destination << endl;
}

void AEROFLOT::setDestination(string destination)
{
    this->destination = destination;
}

void AEROFLOT::setFlightNumber(int flightNumber)
{
    if (flightNumber <= 0)
        throw invalid_argument("Номер рейса должен быть положительным числом!");

    this->flightNumber = flightNumber;
}

void AEROFLOT::setAircraftType(string aircraftType)
{
    if (aircraftType.empty())
        throw invalid_argument("Тип самолета не может быть пустым!");

    this->aircraftType = aircraftType;
}

string AEROFLOT::getDestination() const
{
    return destination;
}

int AEROFLOT::getFlightNumber() const
{
    return flightNumber;
}

string AEROFLOT::getAircraftType() const
{
    return aircraftType;
}

// Оператор ввода
istream& operator>>(istream& in, AEROFLOT& flight)
{
    cout << "Введите пункт назначения: ";
    getline(in >> ws, flight.destination);

    cout << "Введите номер рейса: ";
    int number;
    if (!(in >> number))
        throw invalid_argument("Номер рейса должен быть целым числом!");

    flight.setFlightNumber(number);

    cout << "Введите тип самолета: ";
    getline(in >> ws, flight.aircraftType);

    flight.setAircraftType(flight.aircraftType);

    return in;
}

ostream& operator<<(ostream& out, const AEROFLOT& flight)
{
    out << "Пункт назначения: " << flight.destination << endl;
    out << "Номер рейса: " << flight.flightNumber << endl;
    out << "Тип самолета: " << flight.aircraftType << endl;

    return out;
}

AEROFLOT& AEROFLOT::operator=(const AEROFLOT& other)
{
    if (this != &other)
    {
        destination = other.destination;
        flightNumber = other.flightNumber;
        aircraftType = other.aircraftType;
    }

    cout << "Вызван оператор присваивания AEROFLOT" << endl;

    return *this;
}
