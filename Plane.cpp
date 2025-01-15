// --- Plane.cpp ---
#include "Plane.hpp"

Plane::Plane(const std::string& model, int capacity, const std::string& type, int range)
    : model(model), capacity(capacity), type(type), range(range) {}

void Plane::displayInfo() const {
    std::cout << "Model: " << model << ", Capacity: " << capacity << ", Type: " << type << ", Range: " << range << " km" << std::endl;
}
