#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Constructor of Base class\n";
    }

    ~Base() {
        cout << "Destructor of Base class\n";
    }
};

class Derived : public Base {
private:
    int* dynamicArray;

public:
    Derived() {
        dynamicArray = new int[10];
        cout << "Constructor of Derived class\n";
    }

    ~Derived() {
        delete[] dynamicArray;
        cout << "Destructor of Derived class\n";
    }
};

int main() {
    Base* obj = new Derived();

   

    delete obj; .

    return 0;
}
