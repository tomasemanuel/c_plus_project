// --- Passenger.hpp ---
#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "Person.hpp"
#include <map>

// Forward declaration of Flight class
class Flight;

class Passenger : public Person {
    std::string passportNumber;
    std::string seatClass;
    std::map<std::string,std::shared_ptr<Flight>> flights;
    int LuggageWeight;
    std::vector<std::shared_ptr<Flight>> travelHistory;

public:
    Passenger(const std::string& name, int age, const std::string& gender, const std::string& passportNumber, const std::string& seatClass, int LuggageWeight);
    void displayInfo() const override;
    std::string getPassportNumber() const;
    void addFlight(const std::shared_ptr<Flight>& flight);
    void removeFlight(const std::string& flightNumber);
    void archiveFlight(const std::shared_ptr<Flight>& flight);
    void displayTravelHistory() const;
    void listFlights() const;


};

#endif // PASSENGER_HPP
