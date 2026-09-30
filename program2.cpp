#include <iostream>
#include <string>
using namespace std;

// Class representing a student
class Student {
private:
    // Private data members
    int rollNo;
    string name;
    int totalDays;
    int presentDays;

public:
    // Constructor to initialize student details
    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}

    // Function to mark attendance
    void markAttendance(bool isPresent) {

        // Increase total number of classes/days
        totalDays++;

        // If student is present, increase present days
        if (isPresent) {
            presentDays++;
        }
    }

    // Function to calculate attendance percentage
    double getAttendancePercentage() const {

        // If no classes have been conducted
        if (totalDays == 0) {
            return 0.0;
        }

        // Calculate attendance percentage
        return (presentDays * 100.0) / totalDays;
    }

    // Function to display student attendance
    void display() const {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: "
             << getAttendancePercentage() << "%" << endl;
    }
};

int main() {

    // Create two student objects
    Student s1(101, "Rahul");
    Student s2(102, "Priya");

    // Mark attendance for Rahul
    s1.markAttendance(true);   // Present
    s1.markAttendance(true);   // Present
    s1.markAttendance(false);  // Absent

    // Mark attendance for Priya
    s2.markAttendance(true);   // Present
    s2.markAttendance(true);   // Present
    s2.markAttendance(true);   // Present

    // Display attendance report
    cout << "=== Attendance Report ===" << endl;

    // Display Rahul's attendance
    s1.display();

    // Display Priya's attendance
    s2.display();

    return 0;
}