#include <iostream>
#include <cstring>

class Bike {

private:
    char* brand; // hiệu xe

public:
 Bike() {
        char s[5] = "Bike";
        this->brand = new char[5];
        for (int i = 0; i < 5; i++) {
            this->brand[i] = s[i];
        }
    }

    Bike(char s[]) {
        this->brand = new char[strlen(s) + 1];
        for (int i = 0; i < strlen(s); i++) {
            this->brand[i] = s[i];
        }
        this->brand[strlen(s)] = 0;
    }

    virtual ~Bike() {
        if (this->brand) {
            delete[] this->brand;
        }
    }
    

    virtual void move(int t1) {
        std::cout << brand << ":" << t1 * 12 << " ";
    }
};

class EBike : public Bike {
public:
    EBike(const char s[]) : Bike("EBike") {}

    void move(int t2) override {
        Bike::move(t2 * 2);
    }
};

void display(Bike& a, EBike& b) {
    a.move(2);
    b.move(2);
}

int main() {
    EBike b1("ElectricBike1"), b2("ElectricBike2");
    display(b1, b2);
    return 0;
}

