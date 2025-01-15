// --- Passenger.cpp ---
#include "Passenger.hpp"

Passenger::Passenger(const std::string& name, int age, const std::string& gender, const std::string& passportNumber, const std::string& seatClass, bool hasLuggage)
    : Person(name, age, gender), passportNumber(passportNumber), seatClass(seatClass), hasLuggage(hasLuggage) {}

void Passenger::displayInfo() const {
    Person::displayInfo();
    std::cout << "Passport: " << passportNumber << ", Class: " << seatClass << ", Luggage: " << (hasLuggage ? "Yes" : "No") << std::endl;
}