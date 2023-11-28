class EyedFace : public IFace {
private:
    string shape;
    int eyes;

public:
    EyedFace(const string& sh, const int& e) : shape(sh), eyes(e) {
    }

    void show() override {
        cout << "Shape: " << shape << ", Eyes: " << eyes << endl;
    }

    IFace* clone() const override {
        return new EyedFace(shape, eyes);
    }

    ~EyedFace() {
        shape = "";
        eyes = 0;
    }
};

int main() {
    Face f("Round");
    EyedFace ef("Oval", 2);

    IFace* clonedFace = f.clone();
    IFace* clonedEyedFace = ef.clone();

    cout << "Original Face: ";
    f.show();

    cout << "Cloned Face: ";
    clonedFace->show();

    cout << "Original EyedFace: ";
    ef.show();

    cout << "Cloned EyedFace: ";
    clonedEyedFace->show();

    delete clonedFace;
    delete clonedEyedFace;

    return 0;
}
