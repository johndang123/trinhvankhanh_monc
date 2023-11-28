#include <cmath>
//đinh nghia  một lớp chung abstract  là fuction
class Function {
public:
// hàm ảo để tính giá trị cảu hàm tại x
    virtual double Value(double x) = 0;
    //hàm ao để tính  đạo hàm của hàm  tai x
    virtual double Derive(double x) = 0;
};

class Cos : public Function {
public:
    double Value(double x) override {
        return cos(x);
    }
// tính giá trị đạo hàm tại x 
    double Derive(double x) override {
        return -sin(x);
    }
};

double DaoHamThuong(Function* f, Function* g, double x) {
    if (g != nullptr) {
        return (f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x)) / (g->Value(x) * g->Value(x));
    }
    return 0;
}
//tính đạo hàm của hàm tại x
double DaoHamCuaHamHop(Function* f, Function* g, double x) {
    if (f != nullptr && g != nullptr) {
        return f->Derive(g->Value(x)) * g->Derive(x);
    }
    return 0;
}
