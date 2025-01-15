// --- Plane.hpp ---
#ifndef PLANE_HPP
#define PLANE_HPP

#include <string>
#include <iostream>

class Plane {
    std::string model;
    int capacity;
    std::string type;
    int range;
    int luggageCapacity;

public:
    Plane(const std::string& model, int capacity, const std::string& type, int range, int luggageCapacity);
    void displayInfo() const;
    int getCapacity() const;
    bool canAddPassenger(int flightCapacity) const;
    bool canAddLuggage(int luggage) const;
};

#endif // PLANE_HPP
