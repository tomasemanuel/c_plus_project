// --- Passenger.cpp ---
#include "Passenger.hpp"
#include "Flight.hpp"
Passenger::Passenger(const std::string& name, int age, const std::string& gender, const std::string& passportNumber, const std::string& seatClass, int LuggageWeight)
    : Person(name, age, gender), passportNumber(passportNumber), seatClass(seatClass), LuggageWeight(LuggageWeight) {}

void Passenger::displayInfo() const {
    Person::displayInfo();
    std::cout << "Passport: " << passportNumber << ", Class: " << seatClass << ", Luggage: " << LuggageWeight << std::endl;
}

std::string Passenger::getPassportNumber() const {
    return passportNumber;
}



void Passenger::archiveFlight(const std::shared_ptr<Flight>& flight) {
    travelHistory.push_back(flight);
}

void Passenger::displayTravelHistory() const {
    for (const auto& flight : travelHistory) {
        flight->displayInfo();
    }
}

void Passenger::listFlights() const {
    for (const auto& flight : flights) {
        flight.second->displayInfo();
    }
}



void Passenger::addFlight(const std::shared_ptr<Flight>& flight) {
    flights[flight->getFlightNumber()] = flight;
    flight->addPassenger(std::make_shared<Passenger>(*this));
    flight->addLuggage(LuggageWeight, passportNumber);
}

void Passenger::removeFlight(const std::string& flightNumber) {
    if (flights.find(flightNumber) == flights.end()) {
        throw std::runtime_error("Flight not found!");
    }
    flights[flightNumber]->removeLuggage(passportNumber);
    flights.erase(flightNumber);
}



