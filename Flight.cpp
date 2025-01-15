// --- Flight.cpp ---
#include "Flight.hpp"
#include "Plane.hpp"



Flight::Flight(const std::string& flightNumber, const std::string& destination, const Plane& plane, const std::string& departureTime, const std::string& arrivalTime)
    : flightNumber(flightNumber), destination(destination), plane(plane), departureTime(departureTime), arrivalTime(arrivalTime) {}

void Flight::addPassenger(const std::shared_ptr<Passenger>& passenger) {
    if (passengers.size() < static_cast<size_t>(plane.capacity)) {
        passengers.push_back(passenger);
    } else {
        throw std::runtime_error("Flight is full!");
    }
}

void Flight::displayInfo() const {
    std::cout << "Flight: " << flightNumber << " to " << destination << std::endl;
    std::cout << "Departure: " << departureTime << ", Arrival: " << arrivalTime << std::endl;
    plane.displayInfo();
    std::cout << "Passengers: " << std::endl;
    for (const auto& passenger : passengers) {
        passenger->displayInfo();
    }
}
