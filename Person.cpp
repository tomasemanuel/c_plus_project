// --- Person.cpp ---
#include "Person.hpp"

Person::Person(const std::string& name, int age, const std::string& gender)
    : name(name), age(age), gender(gender) {}

void Person::displayInfo() const {
    std::cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << std::endl;
}
std::string Person::getName() const {
    return name;
}

Person::~Person() {}