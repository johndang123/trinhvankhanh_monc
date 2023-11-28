#include <iostream>
using namespace std;

class MayLoc {
public:
    virtual void nhap() = 0;
    virtual float tinhLuongNuoc() = 0;
    virtual long tinhChiPhi() = 0;
    virtual ~MayLoc() {}
};

class MayLyTam : public MayLoc {
private:
    static const long DON_GIA_THUE_LY_TAM = 50000;
public:
    virtual void nhap() {
        // Thực hiện nhập thông tin cho MayLyTam
    }

    virtual float tinhLuongNuoc() {
        // Thực hiện tính lượng nước được lọc bởi MayLyTam
        return 0.0; // Đổi giá trị này theo logic thực tế
    }

    virtual long tinhChiPhi() {
        return DON_GIA_THUE_LY_TAM;
    }
};

class MayXucTac : public MayLoc {
private:
    static const long DON_GIA_THUE_XUC_TAC = 80000;
public:
    virtual void nhap() {
        // Thực hiện nhập thông tin cho MayXucTac
    }

    virtual float tinhLuongNuoc() {
        // Thực hiện tính lượng nước được lọc bởi MayXucTac
        return 0.0; // Đổi giá trị này theo logic thực tế
    }

    virtual long tinhChiPhi() {
        return DON_GIA_THUE_XUC_TAC;
    }
};

class DanhSachMayLoc {
private:
    MayLoc** _danhSach;
    int _N;
public:
    DanhSachMayLoc() : _N(0), _danhSach(NULL) {}

    ~DanhSachMayLoc() {
        for (int i = 0; i < _N; i++) {
            delete _danhSach[i];
        }
        delete[] _danhSach;
    }

    void nhap() {
        cout << "Nhap so luong may loc: ";
        cin >> this->_N;
        _danhSach = new MayLoc*[_N];
        for (int i = 0; i < _N; i++) {
            int choice = 0;
            cout << "Nhap loai may: 1 = may ly tam, 2 = may xuc tac:\n";
            cin >> choice;
            if (choice == 1) {
                _danhSach[i] = new MayLyTam();
            } else {
                _danhSach[i] = new MayXucTac();
            }
            _danhSach[i]->nhap();
        }
    }

    float tinhLuongNuoc() {
        float sum = 0.0;
        for (int i = 0; i < _N; i++) {
            sum += _danhSach[i]->tinhLuongNuoc();
        }
        return sum;
    }

    long tonhChiPhi() {
        long sum = 0;
        for (int i = 0; i < _N; i++) {
            sum += _danhSach[i]->tinhChiPhi();
        }
        return sum;
    }
};

class Ao {
private:
    int _M;
    DanhSachMayLoc _ds;
public:
    Ao() : _M(0) {}

    ~Ao() {}

    void nhap() {
        cout << "Nhap luong nuoc: ";
        cin >> this->_M;
        cout << "Nhap danh sach may loc:\n";
        this->_ds.nhap();
    }

    bool AoDuocLocHetKhong() {
        return _M <= _ds.tinhLuongNuoc();
    }

    long tongChiPhi() {
        return _ds.tonhChiPhi();
    }
};

int main() {
    Ao ao;
    ao.nhap();
    
    if (ao.AoDuocLocHetKhong()) {
        cout << "Ao co duoc loc het nuoc.\n";
    } else {
        cout << "Ao khong duoc loc het nuoc.\n";
    }

    cout << "Tong chi phi su dung may loc: " << ao.tongChiPhi() << endl;

    return 0;
}
