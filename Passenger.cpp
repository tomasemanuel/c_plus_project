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
    std::cout << "Flights:" << std::endl;
    for (const auto& flight : flights) {
        std::cout << "Flight Number: " << flight.first << std::endl;
    }
}



void Passenger::addFlight(const std::shared_ptr<Flight>& flight) {
    flights[flight->getFlightNumber()] = flight; 
    std::cout << "Flight added successfully!" << std::endl;
}

void Passenger::removeFlight(const std::string& flightNumber) {
    auto it = flights.find(flightNumber);
    if (it != flights.end()) {
        flights.erase(it);
        std::cout << "Flight removed successfully!" << std::endl;
    } else {
        throw std::runtime_error("Flight not found!");
    }
}





