class A_B_Sqrt_X {
private:
    int _a;
    int _b;
    static int _SO_DUOI_DAU_CAN; // Đây là một biến static để lưu giữ giá trị của căn bậc 2 của 7.
public:
    // Các phép toán
    A_B_Sqrt_X operator+(const A_B_Sqrt_X&);
    A_B_Sqrt_X operator-(const A_B_Sqrt_X&);
    A_B_Sqrt_X operator-();
    A_B_Sqrt_X operator*(const A_B_Sqrt_X&);
    
    // Toán tử nhập và xuất
    friend ostream& operator<<(ostream&, const A_B_Sqrt_X&);
    friend istream& operator>>(istream&, A_B_Sqrt_X&);
    
    // Hàm khởi tạo
    A_B_Sqrt_X(const int& a, const int& b) {
        this->_a = a;
        this->_b = b;
    }
};
