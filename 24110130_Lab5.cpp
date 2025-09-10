#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<=b;i++)

class Vehicle {
protected:
    string route;
    int capacity;
    int bookedSeats;
    string status; // "On time" or "Delayed"
public:
    Vehicle(string r, int c) {
        route = r;
        capacity = c;
        bookedSeats = 0;
        status = "On time";
    }

    virtual ~Vehicle() {
        cout << "Vehicle on route " << route << " removed." << endl;
    }

    virtual double calculateTravelTime(double distance) {
        double speed = 50.0; // average km/h
        return distance / speed;
    }

    bool bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    void setStatus(string s) { status = s; }

    virtual void displayInfo() {
        cout << "Vehicle on route: " << route
             << ", Capacity: " << capacity
             << ", Booked: " << bookedSeats
             << ", Status: " << status << endl;
    }
};

class ExpressBus : public Vehicle {
private:
    double speed; // higher than normal bus
public:
    ExpressBus(string r, int c, double s) : Vehicle(r, c) {
        speed = s;
    }

    ~ExpressBus() {
        cout << "ExpressBus on route " << route << " removed." << endl;
    }

    double calculateTravelTime(double distance) override {
        // Express bus is 20% faster
        return (distance / speed) * 0.8;
    }

    void displayInfo() override {
        cout << "Express Bus on route: " << route
             << ", Capacity: " << capacity
             << ", Booked: " << bookedSeats
             << ", Speed: " << speed
             << ", Status: " << status << endl;
    }
};

class Station {
private:
    string name;
    string location;
    string type; // Bus or Train
    vector<Vehicle*> schedule;
public:
    Station(string n, string loc, string t) {
        name = n;
        location = loc;
        type = t;
    }

    ~Station() {
        cout << "Station " << name << " closed." << endl;
    }

    bool addSchedule(Vehicle* v) {
        if (schedule.size() < 10) {
            schedule.push_back(v);
            return true;
        }
        cout << "Schedule full at station " << name << endl;
        return false;
    }

    void removeSchedule(int index) {
        if (index >= 0 && index < (int)schedule.size())
            schedule.erase(schedule.begin() + index);
    }

    void displaySchedule() {
        cout << "Station: " << name << " (" << type
             << "), Location: " << location << endl;
        cout << "Schedules: " << endl;
        for (auto v : schedule) {
            v->displayInfo();
        }
    }
};

class Passenger {
private:
    string name;
    int id;
    vector<Vehicle*> tickets;
public:
    Passenger(string n, int i) {
        name = n;
        id = i;
    }

    ~Passenger() {
        cout << "Passenger " << name << " finished journey." << endl;
    }

    void bookRide(Vehicle* v) {
        if (v->bookSeat()) {
            tickets.push_back(v);
            cout << "Passenger " << name << " booked a ride." << endl;
        } else {
            cout << "Booking failed, no seats left." << endl;
        }
    }

    void displayInfo() {
        cout << "Passenger: " << name << ", ID: " << id << endl;
        cout << "Booked Rides: " << tickets.size() << endl;
    }
};

int main() {
    // Create station
    Station s1("Central Station", "Downtown", "Bus");

    // Create vehicles
    Vehicle v1("Route A", 3);
    ExpressBus eb1("Route B", 2, 80.0);

    // Add to schedule
    s1.addSchedule(&v1);
    s1.addSchedule(&eb1);

    // Create passengers
    Passenger p1("Alice", 101);
    Passenger p2("Bob", 102);

    // Booking
    p1.bookRide(&v1);
    p2.bookRide(&v1);
    p2.bookRide(&v1); // seat still available
    p2.bookRide(&v1); // should fail

    // Display schedules
    cout << "----------------------------------------" << endl;
    s1.displaySchedule();
    cout << "----------------------------------------" << endl;

    // Travel time
    cout << "Normal bus travel time: " << v1.calculateTravelTime(100) << " hours" << endl;
    cout << "Express bus travel time: " << eb1.calculateTravelTime(100) << " hours" << endl;

    // Passenger info
    cout << "----------------------------------------" << endl;
    p1.displayInfo();
    p2.displayInfo();
    cout << "----------------------------------------" << endl;

    return 0;
}
