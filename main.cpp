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
        Plane plane1("Boeing 747", 200, "Commercial", 15000, 5000);
        Plane plane2("Airbus A320", 150, "Commercial", 12000, 4000);

        // Creating Passenger objects
        Passenger passenger1("John Doe", 30, "Male", "P123456789", "Economy", 20);
        Passenger passenger2("Jane Smith", 28, "Female", "P987654321", "Business", 30);

        // Creating Flight objects
        Flight flight1("AA123", "New York", plane1, "2025-01-20 08:00", "2025-01-20 12:00", {}, 0, FlightStatus::Scheduled, {});
        Flight flight2("BB456", "London", plane2, "2025-01-21 10:00", "2025-01-21 14:00", {}, 0, FlightStatus::Scheduled, {});

        // Adding Passengers to Flights
        flight1.addPassenger(std::make_shared<Passenger>(passenger1));
        flight2.addPassenger(std::make_shared<Passenger>(passenger2));

        // Adding Luggage for Passengers
        flight1.addLuggage(20, "P123456789");
        flight2.addLuggage(30, "P987654321");

        // Displaying Flight Info
        std::cout << "=== Flight 1 Info ===\n";
        flight1.displayInfo();
        std::cout << "\n=== Flight 2 Info ===\n";
        flight2.displayInfo();

        // Passenger tries to list flights
        std::cout << "\n=== Passenger 1 Travel History ===\n";
        passenger1.addFlight(std::make_shared<Flight>(flight1));
        passenger1.listFlights();

        std::cout << "\n=== Passenger 2 Travel History ===\n";
        passenger2.addFlight(std::make_shared<Flight>(flight2));
        passenger2.listFlights();

        // Attempt to remove luggage (testing error handling)
        std::cout << "\n=== Attempt to remove luggage ===\n";
        flight1.removeLuggage("P123456789"); // This should succeed

        // Test an error scenario where flight is full
        try {
            std::shared_ptr<Passenger> passenger3 = std::make_shared<Passenger>("Michael Ray", 35, "Male", "P111222333", "Economy", 15);
            flight1.addPassenger(passenger3); // This should throw an error
        } catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << "\n";
        }

        // Changing flight status to "Landed"
        flight1.setStatus(FlightStatus::Landed);
        std::cout << "\n=== Flight 1 Status After Landing ===\n";
        flight1.displayInfo();
        
        // Display all travel history for passengers
        std::cout << "\n=== Displaying All Travel History ===\n";
        passenger1.displayTravelHistory();
        passenger2.displayTravelHistory();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
