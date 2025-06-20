#include <iostream>
#include <cmath>
using namespace std;

class mycomplex {
private:
    double real;
    double imaginary;
public:
    mycomplex(double r, double i) : real(r), imaginary(i) {};
    mycomplex() : real(0), imaginary(0) {};

    void display() {
        cout << this->real << " + " << this->imaginary << "i" << endl;
    }
    //+ overload returns by value and not by reference. why?? 
    mycomplex operator+(mycomplex& c2) {
        return mycomplex(this->real + c2.real, this->imaginary + c2.imaginary);
    }

    double friend magnitude(mycomplex& c);
};

double magnitude(mycomplex& c) {
    double first = c.real * c.real + c.imaginary * c.imaginary;
    double ans = sqrt(first);
    return ans;
}


int main() {
    mycomplex c1(4, 5);
    mycomplex c2(4.5, 7);
    cout << "c1 before changes: " << endl;
    c1.display();
    mycomplex c3 = c1 + c2;
    cout << "after changes" << endl;
    c3.display();
}
