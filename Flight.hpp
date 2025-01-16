#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include "Passenger.hpp"
#include "Plane.hpp"
#include "FlightStatus.hpp"

class Flight : public std::enable_shared_from_this<Flight> {
public:
Flight(const std::string& flightNumber, const std::string& destination, const Plane& plane,
       const std::string& departureTime, const std::string& arrivalTime, 
       const std::vector<std::shared_ptr<Passenger>>& passengers,
       FlightStatus status, 
       const std::unordered_map<std::string, int>& luggage);


    void addPassenger(const std::shared_ptr<Passenger>& passenger);
    std::shared_ptr<Passenger> findPassenger(const std::string& passportNumber) const;
    void addLuggage(const int luggage, const std::string& passportNumber);
    void removeLuggage(const std::string& passportNumber);
    void setStatus(FlightStatus newStatus);
    std::string getFlightNumber() const;
    FlightStatus getStatus() const;
    bool hasLanded() const;
    void displayInfo() const;


private:
    std::string flightNumber;
    std::string destination;
    Plane plane;
    std::string departureTime;
    std::string arrivalTime;
    std::vector<std::shared_ptr<Passenger>> passengers;
    FlightStatus status;
    std::unordered_map<std::string, int> luggage;
    std::unordered_map<std::string, int> passengerLuggage;
    int luggageWeight;
};

#endif // FLIGHT_HPP