#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class representing a smart home device
class SmartDevice {
private:
    // Private data members
    string deviceId;
    string deviceType;
    string location;
    string status;
    string lastUpdated;

public:
    // Constructor to initialize device details
    SmartDevice(string id, string type, string loc,
                string stat, string time)
        : deviceId(id),
          deviceType(type),
          location(loc),
          status(stat),
          lastUpdated(time) {}

    // Function to switch the device ON
    void switchOn(string time) {
        status = "ON";
        lastUpdated = time;
    }

    // Function to switch the device OFF
    void switchOff(string time) {
        status = "OFF";
        lastUpdated = time;
    }

    // Function to change device status
    void changeStatus(string newStatus, string time) {
        status = newStatus;
        lastUpdated = time;
    }

    // Function to display device details
    void displayData() const {
        cout << "Device ID: " << deviceId
             << " | Type: " << deviceType
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated
             << endl;
    }
};

int main() {

    // Create a vector to store multiple smart devices
    vector<SmartDevice> homeDevices;

    // Add smart devices to the vector
    homeDevices.emplace_back(
        "D001", "Light", "Living Room", "OFF", "08:00"
    );

    homeDevices.emplace_back(
        "D002", "Thermostat", "Bedroom", "ON", "08:05"
    );

    homeDevices.emplace_back(
        "D003", "Camera", "Main Door", "ON", "08:10"
    );

    homeDevices.emplace_back(
        "D004", "Door Lock", "Main Door", "OFF", "08:15"
    );

    // Display initial home dashboard
    cout << "=== Smart Home Dashboard ===" << endl;

    // Display all devices
    for (const auto& device : homeDevices) {
        device.displayData();
    }

    // Switch the living room light ON
    homeDevices[0].switchOn("09:00");

    // Switch the camera OFF
    homeDevices[2].switchOff("09:05");

    // Change the door lock status to LOCKED
    homeDevices[3].changeStatus("LOCKED", "09:10");

    // Display updated dashboard
    cout << "\n=== Updated Smart Home Dashboard ===" << endl;

    // Display updated details of all devices
    for (const auto& device : homeDevices) {
        device.displayData();
    }

    return 0;
}