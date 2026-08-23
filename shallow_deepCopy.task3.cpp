#include <iostream>
using namespace std;
class Numbers {
private:
    int size;
    int* ptr;

public:
    Numbers() {
        size = 0;
        ptr = NULL;
    }
    void setData(int s, int values[]) {
        size = s;
        ptr = new int[size];
        for(int i = 0; i < size; i++) {
            ptr[i] = values[i];
        }
    }
    Numbers(const Numbers& obj) {
        size = obj.size;
        ptr = new int[size];
        for(int i = 0; i < size; i++) {
            ptr[i] = obj.ptr[i];
        }
    }
    Numbers& operator=(const Numbers& obj) {
        if(this != &obj) {
            delete[] ptr;
            size = obj.size;
            ptr = new int[size];
            for(int i = 0; i < size; i++) {
                ptr[i] = obj.ptr[i];
            }
        }
        return *this;
    }
    ~Numbers() {
        delete[] ptr;
    }

    void print() {
        cout << "Address: " << ptr << " | Values: ";
        for(int i = 0; i < size; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int temp[] = {10, 20, 30};
    
    Numbers n1;
    n1.setData(3, temp);
    
    cout << "n1 data: ";
    n1.print();

    Numbers n2 = n1; 
    cout << "n2 (copy constructed from n1): ";
    n2.print();

    Numbers n3;
    n3 = n1; 
    cout << "n3 (assigned from n1): ";
    n3.print();

    return 0;
}