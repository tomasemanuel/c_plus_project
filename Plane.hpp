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

public:
    Plane(const std::string& model, int capacity, const std::string& type, int range);
    void displayInfo() const;
};

#endif // PLANE_HPP
