
// --- Flight.hpp ---
#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include "Plane.hpp"
#include <vector>
#include <memory>
#include <stdexcept>
#include <map>


class Passenger;

enum class FlightStatus { Scheduled, InAir, Landed, Cancelled };

class Flight {
    Flight(
        const std::string& flightNumber, 
        const std::string& destination, 
        const Plane& plane, 
        const std::string& departureTime, 
        const std::string& arrivalTime,
        const std::vector<std::shared_ptr<Passenger>>& passengers,
        FlightStatus status,
        const std::vector<std::string>& luggage
    );


public:
    Flight(const std::string& flightNumber, const std::string& destination, const Plane& plane,
           const std::string& departureTime, const std::string& arrivalTime,
           const std::vector<std::shared_ptr<Passenger>>& passengers,
           const int luggageWeight,
              FlightStatus status,  
           const std::map<std::string, int>& passengerLuggage);
 void addPassenger(const std::shared_ptr<Passenger>& passenger);
    void addLuggage(const int luggage, const std::string& passportNumber);
std::shared_ptr<Passenger> findPassenger(const std::string& passportNumber) const;
    
void removeLuggage(const std::string& passportNumber);
    std::string getFlightNumber() const;
    void setStatus(FlightStatus newStatus);
    
    FlightStatus getStatus() const;
    void displayInfo() const;
};

#endif // FLIGHT_HPP
