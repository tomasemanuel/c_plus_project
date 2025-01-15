// --- Plane.cpp ---
#include "Plane.hpp"


Plane::Plane(const std::string& model, int capacity, const std::string& type, int range, int luggageCapacity)
    : model(model), capacity(capacity), type(type), range(range),  luggageCapacity(luggageCapacity) {}



bool Plane::canAddLuggage(int luggage) const {
    if (luggage > luggageCapacity) {
        return false;
    }
    return true;
}


bool Plane::canAddPassenger(int flightCapacity) const {
    if (flightCapacity < capacity) {
        return true;
    }
    return false;
}
int Plane::getCapacity() const {
    return capacity;
}



void Plane::displayInfo() const {
    std::cout << "Model: " << model << ", Capacity: " << capacity << ", Type: " << type << ", Range: " << range << " km" << std::endl;
}
