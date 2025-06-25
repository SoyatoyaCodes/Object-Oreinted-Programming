// Create a class Fraction that represents a mathematical fraction with: 
// • Two private attributes: numerator and denominator. 
// • A friend function addFractions(const Fraction&, const Fraction&) that adds 
// two Fraction objects and returns a new Fraction object. 
// • A friend function multiplyFractions(const Fraction&, const Fraction&) 
// that multiplies two Fraction objects. 
// In the main function: 
// • Define two Fraction objects. 
// • Use the friend functions to add and multiply them. 
// • Print the results using a display() method. 
// Question: Why do we use a friend function instead of a regular member function here?

//cause we want to treat both objs equally. using a friend function allows it to access the private data members
//of both objs otherwise you would have to do something like f1.add(f2); which looks inconvenient

#include <iostream>
using namespace std;
class fraction {
private:
    int numerator;
    int denominator;

public:
    fraction(int n, int d) : numerator(n), denominator(d) {}
    fraction() {}
    friend fraction addfrac(const fraction& f1, const fraction& f2);
    friend fraction multfrac(const fraction& f1, const fraction& f2);
    friend void display(fraction f);

};
fraction addfrac(const fraction& f1, const fraction& f2) {
    fraction f;
    f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;
    return f;
}

fraction multfrac(const fraction& f1, const fraction& f2) {
    fraction f;
    f.numerator = f1.numerator * f2.numerator;
    f.denominator = f1.denominator * f2.denominator;
    return f;
}

void display(fraction f) {
    cout << f.numerator << " / " << f.denominator << endl;
}

int main() {
    fraction f(4, 5);
    fraction f2(55, 2);

    display(addfrac(f, f2));

    display(multfrac(f, f2));

}