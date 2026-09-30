#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


// Base class representing a bank account
class Account {
protected:
    // Common account information
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor to initialize account details
    Account(int accNo, string name, double bal)
        : accountNumber(accNo),
          holderName(name),
          balance(bal) {}

    // Function to deposit money
    void deposit(double amount) {
        balance += amount;

        cout << "Rs. " << amount
             << " deposited successfully." << endl;
    }

    // Virtual function to withdraw money
    // Different accounts can have different withdrawal rules
    virtual void withdraw(double amount) {

        if (amount <= balance) {
            balance -= amount;

            cout << "Rs. " << amount
                 << " withdrawn successfully." << endl;
        }
        else {
            cout << "Insufficient balance." << endl;
        }
    }

    // Pure virtual function for interest calculation
    virtual double calculateInterest() const = 0;

    // Virtual function to display account information
    virtual void displayAccount() const {
        cout << "Account Number: " << accountNumber
             << " | Holder Name: " << holderName
             << " | Balance: Rs. " << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() = default;
};


// Derived class for Savings Account
class SavingsAccount : public Account {
private:
    // Interest rate for savings account
    double interestRate;

public:
    // Constructor
    SavingsAccount(int accNo, string name,
                   double bal, double rate)
        : Account(accNo, name, bal),
          interestRate(rate) {}

    // Calculate savings account interest
    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    // Display savings account information
    void displayAccount() const override {

        cout << "=== Savings Account ===" << endl;

        Account::displayAccount();

        cout << "Interest Rate: "
             << interestRate << "%" << endl;

        cout << "Calculated Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Derived class for Current Account
class CurrentAccount : public Account {
private:
    // Minimum balance required
    double minimumBalance;

public:
    // Constructor
    CurrentAccount(int accNo, string name,
                   double bal, double minBal)
        : Account(accNo, name, bal),
          minimumBalance(minBal) {}

    // Current account does not provide normal interest
    double calculateInterest() const override {
        return 0.0;
    }

    // Override withdrawal function
    void withdraw(double amount) override {

        // Check whether minimum balance will be maintained
        if (balance - amount >= minimumBalance) {

            balance -= amount;

            cout << "Rs. " << amount
                 << " withdrawn from Current Account."
                 << endl;
        }
        else {
            cout << "Withdrawal not allowed."
                 << " Minimum balance must be maintained."
                 << endl;
        }
    }

    // Display current account information
    void displayAccount() const override {

        cout << "=== Current Account ===" << endl;

        Account::displayAccount();

        cout << "Minimum Balance: Rs. "
             << minimumBalance << endl;

        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Derived class for Fixed Deposit Account
class FixedDepositAccount : public Account {
private:
    // Interest rate for fixed deposit
    double interestRate;

    // Deposit period in years
    int years;

public:
    // Constructor
    FixedDepositAccount(int accNo, string name,
                        double bal, double rate,
                        int y)
        : Account(accNo, name, bal),
          interestRate(rate),
          years(y) {}

    // Calculate fixed deposit interest
    double calculateInterest() const override {

        // Simple interest formula
        return balance * interestRate * years / 100;
    }

    // Display fixed deposit information
    void displayAccount() const override {

        cout << "=== Fixed Deposit Account ==="
             << endl;

        Account::displayAccount();

        cout << "Interest Rate: "
             << interestRate << "%" << endl;

        cout << "Deposit Period: "
             << years << " years" << endl;

        cout << "Calculated Interest: Rs. "
             << calculateInterest() << endl;
    }
};


int main() {

    // Create a vector of Account base-class pointers
    vector<unique_ptr<Account>> accounts;

    // Create Savings Account
    accounts.push_back(
        make_unique<SavingsAccount>(
            1001,
            "Rahul",
            50000,
            4.0
        )
    );

    // Create Current Account
    accounts.push_back(
        make_unique<CurrentAccount>(
            1002,
            "Priya",
            100000,
            10000
        )
    );

    // Create Fixed Deposit Account
    accounts.push_back(
        make_unique<FixedDepositAccount>(
            1003,
            "Amit",
            200000,
            7.0,
            2
        )
    );


    cout << "=== Banking System ===" << endl;
    cout << endl;


    // Deposit money into the first account
    cout << "Savings Account Transaction:"
         << endl;

    accounts[0]->deposit(5000);

    cout << endl;


    // Withdraw money from the second account
    cout << "Current Account Transaction:"
         << endl;

    accounts[1]->withdraw(20000);

    cout << endl;


    // Display all account information
    cout << "=== Account Details ==="
         << endl << endl;

    for (const auto& account : accounts) {

        // Runtime polymorphism
        account->displayAccount();

        cout << endl;
    }

    return 0;
}