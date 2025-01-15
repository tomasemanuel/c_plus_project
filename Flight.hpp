
// --- Flight.hpp ---
#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include "Plane.hpp"
#include "Passenger.hpp"
#include <vector>
#include <memory>
#include <stdexcept>

class Flight {
    std::string flightNumber;
    std::string destination;
    Plane plane;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<std::shared_ptr<Passenger>> passengers;

public:
    Flight(const std::string& flightNumber, const std::string& destination, const Plane& plane, const std::string& departureTime, const std::string& arrivalTime);
    void addPassenger(const std::shared_ptr<Passenger>& passenger);
    void displayInfo() const;
};

#endif // FLIGHT_HPP
