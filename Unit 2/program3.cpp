#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;


// Base class representing a vehicle
class Vehicle {
protected:
    // Common vehicle information
    string vehicleId;
    string registrationNumber;
    double fuelLevel;

public:
    // Constructor
    Vehicle(string vid, string reg)
        : vehicleId(vid),
          registrationNumber(reg),
          fuelLevel(100.0) {}

    // Function to start the vehicle engine
    void startEngine() const {
        cout << "Vehicle "
             << vehicleId
             << " engine started." << endl;
    }

    // Function to refuel the vehicle
    void refuel(double amount) {

        // Add fuel to current fuel level
        fuelLevel += amount;

        // Maximum fuel level is 100%
        if (fuelLevel > 100.0) {
            fuelLevel = 100.0;
        }
    }

    // Virtual function to display vehicle information
    virtual void displayInfo() const {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};


// Derived class for Truck
class Truck : public Vehicle {
private:
    // Truck-specific property
    double cargoCapacity;

public:
    // Constructor
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg),
          cargoCapacity(capacity) {}

    // Override displayInfo function
    void displayInfo() const override {

        cout << "Truck | ";

        // Display common vehicle information
        Vehicle::displayInfo();

        // Display truck-specific information
        cout << "Cargo capacity: "
             << cargoCapacity
             << " tonnes" << endl;
    }
};


// Derived class for Delivery Van
class DeliveryVan : public Vehicle {
private:
    // Number of packages in the van
    int packageCount;

public:
    // Constructor
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg),
          packageCount(packages) {}

    // Override displayInfo function
    void displayInfo() const override {

        cout << "Delivery Van | ";

        // Display common vehicle information
        Vehicle::displayInfo();

        // Display package information
        cout << "Packages loaded: "
             << packageCount << endl;
    }
};


// Derived class for Delivery Bike
class Bike : public Vehicle {
private:
    // Indicates whether bike has a delivery box
    bool hasDeliveryBox;

public:
    // Constructor
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg),
          hasDeliveryBox(hasBox) {}

    // Override displayInfo function
    void displayInfo() const override {

        cout << "Delivery Bike | ";

        // Display common vehicle information
        Vehicle::displayInfo();

        // Display delivery box status
        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};


int main() {

    // Vector stores different types of vehicles
    vector<unique_ptr<Vehicle>> fleet;

    // Add truck to fleet
    fleet.push_back(
        make_unique<Truck>(
            "V001", "MH12-AB-1234", 10.5
        )
    );

    // Add delivery van to fleet
    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002", "MH12-CD-5678", 50
        )
    );

    // Add delivery bike to fleet
    fleet.push_back(
        make_unique<Bike>(
            "V003", "MH12-EF-9012", true
        )
    );

    // Display fleet status
    cout << "=== Fleet Status ===" << endl;

    // Access every vehicle using base class pointer
    for (const auto& vehicle : fleet) {

        // Start vehicle engine
        vehicle->startEngine();

        // Display vehicle-specific information
        vehicle->displayInfo();

        cout << endl;
    }

    return 0;
}