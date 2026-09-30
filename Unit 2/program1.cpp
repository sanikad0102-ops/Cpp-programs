#include <iostream>
#include <string>
using namespace std;

// Base class representing an Employee
class Employee {
protected:
    // Protected data members can be accessed by derived classes
    int empId;
    string name;
    string department;

public:
    // Constructor to initialize employee details
    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept) {}

    // Function to display basic employee information
    void displayBasicInfo() const {
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
    }

    // Pure virtual function
    // It makes Employee an abstract class
    virtual double calculateSalary() const = 0;

    // Virtual destructor
    virtual ~Employee() = default;
};


// Derived class for Full-Time Employee
class FullTimeEmployee : public Employee {
private:
    // Monthly salary of full-time employee
    double monthlySalary;

public:
    // Constructor
    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary) {}

    // Override calculateSalary function
    double calculateSalary() const override {
        return monthlySalary;
    }

    // Display full-time employee details
    void display() const {
        displayBasicInfo();

        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};


// Derived class for Part-Time Employee
class PartTimeEmployee : public Employee {
private:
    // Hourly payment rate
    double hourlyRate;

    // Number of hours worked
    int hoursWorked;

public:
    // Constructor
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Calculate salary based on hours worked
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    // Display part-time employee details
    void display() const {
        displayBasicInfo();

        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};


// Derived class for Intern
class Intern : public Employee {
private:
    // Stipend received by intern
    double stipend;

public:
    // Constructor
    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept), stipend(stipendAmount) {}

    // Return intern stipend
    double calculateSalary() const override {
        return stipend;
    }

    // Display intern details
    void display() const {
        displayBasicInfo();

        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;
    }
};


int main() {

    // Create a full-time employee object
    FullTimeEmployee f1(
        101, "Amit", "IT", 65000
    );

    // Create a part-time employee object
    PartTimeEmployee p1(
        102, "Sneha", "HR", 250, 120
    );

    // Create an intern object
    Intern i1(
        103, "Rohan", "Marketing", 15000
    );

    // Display employee payroll
    cout << "=== Employee Payroll ===" << endl;

    f1.display();
    p1.display();
    i1.display();

    return 0;
}