#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Location class to represent GPS coordinates
class Location {
public:
    double latitude;
    double longitude;

    Location(double lat, double lon) : latitude(lat), longitude(lon) {}
};

// Base class for User
class User {
protected:
    string name;
    string phone;
public:
    User(string name, string phone) : name(name), phone(phone) {}

    virtual void displayInfo() {
        cout << "Name: " << name << ", Phone: " << phone << endl;
    }
};

// Derived class Rider
class Rider : public User {
public:
    Rider(string name, string phone) : User(name, phone) {}

    void requestRide(Location start, Location end) {
        cout << "Requesting a ride from (" << start.latitude << ", " << start.longitude 
             << ") to (" << end.latitude << ", " << end.longitude << ")" << endl;
    }

    void cancelRide() {
        cout << "Ride canceled" << endl;
    }

    void displayInfo() override {
        cout << "Rider - ";
        User::displayInfo();
    }
};

// Derived class Driver
class Driver : public User {
private:
    string vehicleDetails;
public:
    Driver(string name, string phone, string vehicle) : User(name, phone), vehicleDetails(vehicle) {}

    void acceptRide() {
        cout << "Ride accepted" << endl;
    }

    void startRide() {
        cout << "Ride started" << endl;
    }

    void completeRide() {
        cout << "Ride completed" << endl;
    }

    void displayInfo() override {
        cout << "Driver - ";
        User::displayInfo();
        cout << "Vehicle: " << vehicleDetails << endl;
    }

    friend void displayDriverInfo(Driver& d); // Friend function
};

// Vehicle class
class Vehicle {
public:
    string licensePlate;
    string model;

    Vehicle(string plate, string model) : licensePlate(plate), model(model) {}
};

// Ride class
class Ride {
private:
    Rider* rider;
    Driver* driver;
    Location start;
    Location end;
    double fare;
public:
    Ride(Rider* r, Driver* d, Location s, Location e) : rider(r), driver(d), start(s), end(e), fare(0) {}

    void calculateFare() {
        // Simple fare calculation based on distance
        fare = 50.0; // Assume a static fare for simplicity
        cout << "Fare calculated: $" << fare << endl;
    }

    void startRide() {
        cout << "Ride started from (" << start.latitude << ", " << start.longitude << ") to (" 
             << end.latitude << ", " << end.longitude << ")" << endl;
    }

    void endRide() {
        cout << "Ride ended" << endl;
    }

    double getFare() {
        return fare;
    }
};

// Friend function to display driver's info
void displayDriverInfo(Driver& d) {
    cout << "Driver's Name: " << d.name << ", Vehicle: " << d.vehicleDetails << endl;
}

int main() {
    Rider rider("John Doe", "123-456-7890");
    Driver driver("Jane Smith", "098-765-4321", "Toyota Prius");
    Location start(37.7749, -122.4194); // San Francisco
    Location end(34.0522, -118.2437);   // Los Angeles

    rider.displayInfo();
    driver.displayInfo();

    Ride ride(&rider, &driver, start, end);
    rider.requestRide(start, end);
    driver.acceptRide();
    ride.calculateFare();
    ride.startRide();
    ride.endRide();

    cout << "Total Fare: $" << ride.getFare() << endl;

    displayDriverInfo(driver);

    return 0;
}
