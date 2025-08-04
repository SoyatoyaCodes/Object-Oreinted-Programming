// Task 3:  
// Design a template class Complex to represent complex numbers.  
// Implement addition, subtraction, multiplication, and division operations for complex numbers.  
// Create template specializations for integer and floating-point complex numbers to optimize operations. Test the 
// class and its specializations with different complex number operations. 
#include <iostream>
using namespace std;

template <typename T>
class Complex {
public:
    T real, imag;

    Complex(T r = 0, T i = 0) : real(r), imag(i) {}

    Complex<T> operator+(const Complex<T>& other) const {
        return Complex<T>(real + other.real, imag + other.imag);
    }

    Complex<T> operator-(const Complex<T>& other) const {
        return Complex<T>(real - other.real, imag - other.imag);
    }

    Complex<T> operator*(const Complex<T>& other) const {
        return Complex<T>(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex<T> operator/(const Complex<T>& other) const {
        T denom = other.real * other.real + other.imag * other.imag;
        return Complex<T>(
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        );
    }

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }
};

// Specialization for int
template <>
class Complex<int> {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex<int> operator+(const Complex<int>& other) const {
        return Complex<int>(real + other.real, imag + other.imag);
    }

    Complex<int> operator-(const Complex<int>& other) const {
        return Complex<int>(real - other.real, imag - other.imag);
    }

    Complex<int> operator*(const Complex<int>& other) const {
        return Complex<int>(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex<int> operator/(const Complex<int>& other) const {
        int denom = other.real * other.real + other.imag * other.imag;
        return Complex<int>(
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        );
    }

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }
};

// Specialization for float
template <>
class Complex<float> {
public:
    float real, imag;

    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex<float> operator+(const Complex<float>& other) const {
        return Complex<float>(real + other.real, imag + other.imag);
    }

    Complex<float> operator-(const Complex<float>& other) const {
        return Complex<float>(real - other.real, imag - other.imag);
    }

    Complex<float> operator*(const Complex<float>& other) const {
        return Complex<float>(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex<float> operator/(const Complex<float>& other) const {
        float denom = other.real * other.real + other.imag * other.imag;
        return Complex<float>(
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        );
    }

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }
};

int main() {
    Complex<int> c1(4, 3), c2(2, -1);
    Complex<int> ci_add = c1 + c2;
    Complex<int> ci_div = c1 / c2;

    Complex<float> f1(1.5f, 2.5f), f2(0.5f, -1.5f);
    Complex<float> cf_mul = f1 * f2;

    Complex<double> d1(2.0, 3.0), d2(1.0, 4.0);
    Complex<double> cd_sub = d1 - d2;

    ci_add.display();
    ci_div.display();
    cf_mul.display();
    cd_sub.display();

    return 0;
}
