#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;

public:
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    MyString& operator=(const MyString& other) {
        if(this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }
    void setStr(const char* s) {
        delete[] str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    void display() {
        cout << "String: " << str << " (Address: " << (void*)str << ")" << endl;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2 = s1;

    cout << "s1: ";
    s1.display();
    
    cout << "s2: ";
    s2.display();

    s2.setStr("World");
    
    cout << "After modifying s2:" << endl;
    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();
    return 0;
}