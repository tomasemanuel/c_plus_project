// --- Passenger.hpp ---
#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "Person.hpp"

class Passenger : public Person {
    std::string passportNumber;
    std::string seatClass;
    bool hasLuggage;

public:
    Passenger(const std::string& name, int age, const std::string& gender, const std::string& passportNumber, const std::string& seatClass, bool hasLuggage);
    void displayInfo() const override;
};

#endif // PASSENGER_HPP
