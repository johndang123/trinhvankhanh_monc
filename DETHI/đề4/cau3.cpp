#include <iostream>
#include <vector>
using namespace std;

class Phone_Fee {
private:
    float _time;

public:
    static long PRICE_PHONE;
    long calFee() {
        return PRICE_PHONE * _time;
    }
};

long Phone_Fee::PRICE_PHONE = 1000;

class Internet_Fee {
private:
    long _luongTruyCap;

public:
    static long PRICE_INTERNET;
    long calFee() {
        return PRICE_INTERNET * _luongTruyCap;
    }
};

long Internet_Fee::PRICE_INTERNET = 200;

class Customer {
private:
    string FullName;
    string ID;
    string Address;

public:
    void dangKy() {
        cin.ignore();
        cout << "Nhap ho va ten: ";
        getline(cin, FullName);
        cout << "Nhap so chung minh: ";
        cin >> ID;
        cin.ignore();
        cout << "Nhap dia chi: ";
        getline(cin, Address);
    }

    void xuat() {
        cout << "Ho va ten: " << FullName << endl;
        cout << "So chung minh: " << ID << endl;
        cout << "Dia chi: " << Address << endl;
    }
};

class Cost {
protected:
    Phone_Fee _phone_fee;

public:
    static long VAT;
    virtual long calFee() = 0;
    virtual ~Cost() {}
};

long Cost::VAT = 10;

class Basic : public Cost {
private:
    Internet_Fee _internet_fee;

public:
    long calFee() override {
        return _phone_fee.calFee() + _internet_fee.calFee() + 0.1 * VAT;
    }
};

class Data_Fee : public Cost {
private:
    long _luongTruyCap;

public:
    static long NGUONG_MIEN_PHI;
    static long CUOC_THUE_BAO;

    long calFee() override {
        long phone_fee = _phone_fee.calFee();
        long internet_fee = 0;

        if (_luongTruyCap > NGUONG_MIEN_PHI) {
            Internet_Fee temp;
            temp.calFee();
            internet_fee = CUOC_THUE_BAO + temp.calFee();
        }

        return phone_fee + internet_fee;
    }
};

long Data_Fee::NGUONG_MIEN_PHI = 1000;
long Data_Fee::CUOC_THUE_BAO = 50000;

class Data_Fix : public Cost {
public:
    static long MUC_CO_DINH;

    long calFee() override {
        return (float)0.9 * _phone_fee.calFee() + MUC_CO_DINH;
    }
};

long Data_Fix::MUC_CO_DINH = 1000000;

class Contract {
private:
    Customer _cus;
    Cost* _cost;

public:
    void dangKy() {
        _cus.dangKy();
        cout << "Chon goi cuoc: 1-Basic, 2-Data_Fee, 3-Data_Fix:\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            _cost = new Basic();
        } else if (choice == 2) {
            _cost = new Data_Fee();
        } else if (choice == 3) {
            _cost = new Data_Fix();
        } else {
            _cost = new Basic();
        }
    }

    void thongBao() {
        cout << "Khach hang:\n";
        _cus.xuat();
        cout << "Tien cuoc goi cuoc la:" << _cost->calFee() << endl;
    }

    ~Contract() {
        if (_cost) {
            delete _cost;
            _cost = NULL;
        }
    }
};

class QuanLy {
private:
    vector<Contract*> _ds;

public:
    void dangKy() {
        int n;
        cout << "Nhap luong hop dong:";
        cin >> n;
        for (int i = 0; i < n; i++) {
            Contract* c = new Contract();
            c->dangKy();
            _ds.push_back(c);
        }
    }

    void thongBao() {
        for (int i = 0; i < _ds.size(); i++) {
            _ds[i]->thongBao();
        }
    }

    ~QuanLy() {
        for (int i = 0; i < _ds.size(); i++) {
            if (_ds[i]) {
                delete _ds[i];
            }
        }
        _ds.clear();
    }
};

int main() {
    QuanLy ql;
    ql.dangKy();
    ql.thongBao();

    return 0;
}
