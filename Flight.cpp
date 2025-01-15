// --- Flight.cpp ---
#include "Flight.hpp"
#include "Plane.hpp"


Flight::Flight(
    const std::string& flightNumber, 
    const std::string& destination, 
    const Plane& plane, 
    const std::string& departureTime, 
    const std::string& arrivalTime,
    const std::vector<std::shared_ptr<Passenger>>& passengers,
    FlightStatus status,
    const std::vector<std::string>& luggage
) : flightNumber(flightNumber), destination(destination), plane(plane),
    departureTime(departureTime), arrivalTime(arrivalTime), passengers(passengers),
     status(status), luggage(luggage) {
   
}


void Flight::addPassenger(const std::shared_ptr<Passenger>& passenger) {
    if (plane.canAddPassenger(passengers.size())) {
        passengers.push_back(passenger);
    } else {
        throw std::runtime_error("Flight is full!");
    }
}

void Flight::addLuggage(const int luggage, const std::string& passportNumber) {
    if (passengerLuggage.find(passportNumber) != passengerLuggage.end()) {
        throw std::runtime_error("Passenger already has luggage!");
    }
    if (plane.canAddLuggage(luggageWeight + luggage)) {
        passengerLuggage[passportNumber] = luggage;
        luggageWeight += luggage;
    } else {
        throw std::runtime_error("Luggage is too heavy!");
    }
}

std::shared_ptr<Passenger> Flight::findPassenger(const std::string& passportNumber) const {
    for (const auto& passenger : passengers) {
        if (passenger->getPassportNumber() == passportNumber) {
            return passenger;
        }
    }
    throw std::runtime_error("Passenger not found!");
}

std::string Flight::getFlightNumber() const {
    return flightNumber;
}


void Flight::setStatus(FlightStatus newStatus) {
    if (newStatus == FlightStatus::Landed) {
        for (const auto& passenger : passengers) {
            passenger->archiveFlight();
            passenger->removeFlight(flightNumber);
        }
    }
    status = newStatus;
}

FlightStatus Flight::getStatus() const {
    return status;
}

void Flight::removeLuggage(const std::string& passportNumber) {
    if (passengerLuggage.find(passportNumber) == passengerLuggage.end()) {
        throw std::runtime_error("Passenger has no luggage!");
    }
    luggageWeight -= passengerLuggage[passportNumber];
    passengerLuggage.erase(passportNumber);
}





void Flight::displayInfo() const {
    std::cout << "Flight Report for " << flightNumber << ":\n";
    std::cout << "Destination: " << destination << "\n";
    std::cout << "Departure: " << departureTime << ", Arrival: " << arrivalTime << "\n";
    std::cout << "Passengers: " << passengers.size() << "/" << plane.getCapacity() << "\n";
    std::cout << "Total Luggage Weight: " << luggageWeight << " kg\n";

    std::cout << "Passenger Details:\n";
    for (const auto& passenger : passengers) {
        passenger->displayInfo();
        std::cout << "Luggage: " << passengerLuggage.at(passenger->getPassportNumber()) << " kg\n";
    }
}
