#include <iostream>
#include <string>
using namespace std;

// Class representing an e-commerce product
class Product {
private:
    // Private data members
    int productId;
    string productName;
    double price;
    int stockQuantity;

    // Static data member shared by all objects
    static int totalProducts;

public:
    // Constructor to initialize product details
    Product(int id, string name, double p, int stock)
        : productId(id), productName(name),
          price(p), stockQuantity(stock) {

        // Increase total product count
        totalProducts++;
    }

    // Inline function to get product ID
    inline int getId() const {
        return productId;
    }

    // Inline function to get product name
    inline string getName() const {
        return productName;
    }

    // Inline function to get product price
    inline double getPrice() const {
        return price;
    }

    // Function to update stock quantity
    void updateStock(int quantity) {
        stockQuantity = quantity;
    }

    // Static function to get total number of products
    static int getTotalProducts() {
        return totalProducts;
    }

    // Function to display product details
    void display() const {
        cout << "ID: " << productId
             << " | Product: " << productName
             << " | Price: Rs. " << price
             << " | Stock: " << stockQuantity << endl;
    }

    // Destructor
    ~Product() {

        // Decrease total product count when object is destroyed
        totalProducts--;
    }
};

// Initialize static data member
int Product::totalProducts = 0;

int main() {

    // Create three product objects
    Product p1(1001, "Laptop", 55000, 15);
    Product p2(1002, "Mouse", 450, 50);
    Product p3(1003, "Keyboard", 1200, 30);

    // Display product catalog
    cout << "=== Product Catalog ===" << endl;

    // Display details of each product
    p1.display();
    p2.display();
    p3.display();

    // Display total number of active products
    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts() << endl;

    return 0;
}