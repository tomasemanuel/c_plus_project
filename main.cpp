#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <stdexcept>
#include "Person.hpp"
#include "Passenger.hpp"
#include "Flight.hpp"
#include "Plane.hpp"

int main() {
    try {
        // Creating Plane objects
        Plane plane1("Boeing 747", 2, "Commercial", 15000, 5000);
        Plane plane2("Airbus A320", 150, "Commercial", 12000, 4000);

        // Creating Passenger objects
        auto passenger1 = std::make_shared<Passenger>("John Doe", 30, "Male", "P123456789", "Economy", 20);
        auto passenger2 = std::make_shared<Passenger>("Jane Smith", 28, "Female", "P987654321", "Business", 30);

        // Creating Flight objects
        auto flight1 = std::make_shared<Flight>(
            "AA123", "New York", plane1, "2025-01-20 08:00", "2025-01-20 12:00", 
            std::vector<std::shared_ptr<Passenger>>{}, FlightStatus::Scheduled, 
            std::unordered_map<std::string, int>{}
        );

        auto flight2 = std::make_shared<Flight>(
            "BB456", "London", plane2, "2025-01-21 10:00", "2025-01-21 14:00", 
            std::vector<std::shared_ptr<Passenger>>{}, FlightStatus::Scheduled, 
            std::unordered_map<std::string, int>{}
        );

        // Adding passengers to flights
        flight1->addPassenger(passenger1);
        flight2->addPassenger(passenger2);
        flight2->addPassenger(passenger1);

        // Adding flights to passengers
        passenger1->addFlight(flight1);
        passenger1->addFlight(flight2);
        passenger2->addFlight(flight2);

        // Adding Luggage for Passengers
        flight1->addLuggage(20, "P123456789");
        flight2->addLuggage(30, "P987654321");
        flight2->addLuggage(20, "P123456789");

        // Displaying Flight Info
        std::cout << "\n\n=== Flight 1 Info ===\n";
        flight1->displayInfo();
        std::cout << "\n\n=== Flight 2 Info ===\n";
        flight2->displayInfo();

        // Passenger tries to list flights
        std::cout << "\n\n=== Passenger 1 Current Travel Trips ===\n";
        passenger1->listFlights();

        std::cout << "\n\n=== Passenger 2 Current Travel Trips ===\n";
        passenger2->listFlights();

        // Removing luggage and testing error handling
        std::cout << "\n=== Attempt to remove luggage ===\n";
        flight1->removeLuggage("P123456789"); // Should succeed
        std::cout << "\n=== Flight 1 Info After Removing Luggage ===\n";
        flight1->displayInfo();

        // Testing luggage removal error
        std::cout << "\n=== Error check with no luggage ===\n";
        try {
            flight1->removeLuggage("P123456789"); // Should throw an error
        } catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << "\n";
        }

        // Attempt to add a passenger to a full flight
        std::cout << "\n=== Attempt to add a passenger to a full flight ===\n";
        try {
            auto passenger3 = std::make_shared<Passenger>("Michael Ray", 35, "Male", "P111222333", "Economy", 15);
            flight1->addPassenger(passenger3); // Should throw an error if flight is full
        } catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << "\n";
        }

        // Changing flight status to "Landed"
        std::cout << "\n=== Changing flight status to Landed ===\n";
        flight1->setStatus(FlightStatus::Landed);
        std::cout << "\n=== Flight 1 Status After Landing ===\n";
        flight1->displayInfo();

        // Displaying all travel history for passengers
        std::cout << "\n=== Displaying All Travel History ===\n";
        passenger1->displayTravelHistory();
        passenger2->displayTravelHistory();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
