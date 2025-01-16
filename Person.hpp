// --- Person.hpp ---
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    int age;
    std::string gender;

public:
    Person(const std::string& name, int age, const std::string& gender);
    virtual void displayInfo() const;
    std::string getName() const;
    virtual ~Person();
};

#endif // PERSON_HPP
