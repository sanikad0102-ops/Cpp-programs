#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;


// Base abstract class for payment methods
class PaymentMethod {
protected:
    // Common payment information
    string transactionId;
    double amount;

public:
    // Constructor
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt) {}

    // Pure virtual function
    // Every payment method must implement this function
    virtual bool processPayment() const = 0;

    // Virtual destructor
    virtual ~PaymentMethod() = default;
};


// Derived class for Credit Card Payment
class CreditCardPayment : public PaymentMethod {
private:
    // Masked credit card number
    string maskedCardNumber;

public:
    // Constructor
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt),
          maskedCardNumber(card) {}

    // Process credit card payment
    bool processPayment() const override {

        cout << "Credit-card transaction "
             << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;

        return true;
    }
};


// Derived class for UPI Payment
class UPIPayment : public PaymentMethod {
private:
    // UPI ID
    string upiId;

public:
    // Constructor
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi) {}

    // Process UPI payment
    bool processPayment() const override {

        cout << "UPI transaction "
             << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;

        return true;
    }
};


// Derived class for Net Banking Payment
class NetBankingPayment : public PaymentMethod {
private:
    // Bank name
    string bankName;

public:
    // Constructor
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank) {}

    // Process net banking payment
    bool processPayment() const override {

        cout << "Net-banking transaction "
             << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;

        return true;
    }
};


int main() {

    // Vector stores pointers to different payment objects
    vector<unique_ptr<PaymentMethod>> payments;

    // Add credit card payment
    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX-1234"
        )
    );

    // Add UPI payment
    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"
        )
    );

    // Add net banking payment
    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"
        )
    );

    // Display payment gateway information
    cout << "=== Payment Gateway ===" << endl;

    // Process every payment
    for (const auto& payment : payments) {
        payment->processPayment();
    }

    return 0;
}