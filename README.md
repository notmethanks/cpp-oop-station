Public Transportation Station Management System
📌 Introduction

This is a basic C++ project that simulates a simple Public Transportation Station Management System.
The program demonstrates core Object-Oriented Programming (OOP) concepts such as classes, objects, inheritance, constructor/destructor, and polymorphism.

The system manages:

Stations: Store schedules of vehicles.

Vehicles: Have routes, capacity, and status.

Express Buses: Inherit from Vehicle, travel faster, and override travel time calculation.

Passengers: Can book or cancel tickets.

⚙️ Features

Create and manage stations.

Add vehicles and express buses to schedules (limit: 10 schedules per station).

Book passengers onto vehicles (with capacity check).

Calculate and compare travel times for regular vs. express buses.

Show details of stations, vehicles, and passengers.

Destructor messages show object lifecycle when program ends.

🛠️ Technologies

Language: C++ (C++11 or later)

Compiler: Tested with g++

🚀 How to Run

Clone the repository:

git clone https://github.com/your-username/transport-station-management.git
cd transport-station-management


Compile the code:

g++ main.cpp -o transport


Run the program:

./transport

📖 Example Output

=== Public Transportation System Demo ===

--- Scheduling Vehicles ---
Added vehicle to station schedule.
Added vehicle to station schedule.
Station Central schedules:
Vehicle on route Route A ...
Express Bus on route Route B ...

--- Booking Passengers ---
Passenger booked on Route A
Passenger booked on Route A
Vehicle is full
Passenger booked on Route B

--- Travel Time Calculation ---
Regular bus time: 2 hours
Express bus time: 1.25 hours

=== End of Demo ===

📚 Learning Notes

Constructor initializes object attributes when created.

Destructor shows when objects are destroyed.

Inheritance allows ExpressBus to extend Vehicle.

Virtual functions enable polymorphism (calling the right method depending on the actual object type).

✨ Author

Student project for practicing OOP in C++.

Code and report are written and customized by myself, with AI (ChatGPT) used only for brainstorming and clarifications.
