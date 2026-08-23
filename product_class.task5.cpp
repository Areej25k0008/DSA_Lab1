#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int* qty;

public:
    Product(string n, int q) {
        name = n;
        qty = new int;
        *qty = q;
    }
    Product(const Product& p) {
        name = p.name;
        qty = new int;
        *qty = *(p.qty);
    }
    Product& operator=(const Product& p) {
        if(this != &p) {
            name = p.name;
            delete qty;
            qty = new int;
            *qty = *(p.qty);
        }
        return *this;
    }
    ~Product() {
        delete qty;
    }

    void setQty(int q) {
        *qty = q;
    }

    void show() {
        cout << "Product: " << name << ", Quantity: " << *qty << " (Address: " << qty << ")" << endl;
    }
};

int main() {
    Product p1("Laptop", 5);
    cout << "Original p1: ";
    p1.show();

    Product p2 = p1; 
    cout << "p2 after copy cons: ";
    p2.show();

    Product p3("Mobile", 2);
    p3 = p1; 
    cout << "p3 after assignment operator: ";
    p3.show();

    p2.setQty(10);
    p3.setQty(99);

    cout << "\nAfter changing p2 and p3:" << endl;
    cout << "p1: ";
    p1.show();
    cout << "p2: ";
    p2.show();
    cout << "p3: ";
    p3.show();
    return 0;
}