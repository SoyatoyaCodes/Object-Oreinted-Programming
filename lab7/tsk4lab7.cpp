//  Requirements: 
//  Demonstrate the use of dynamic_cast and catch a failed cast exception
//  Create a base class (e.g., Shape) with a virtual function and a virtual destructor. 
//  Derive at least one class (e.g., Circle). 
//  Create an object that is not a Circle (or use a base class object). 
//  Attempt to cast to Circle& using dynamic_cast and catch the std::bad_cast exception. 

#include <iostream>
using namespace std;

class shape {
public:
    virtual void type() {
        cout << "default" << endl;
    }
    virtual ~shape() {}
};

class circle : public shape {
public:
    void type() override {
        cout << "circle shape" << endl;
    }
};

int main() {
    shape s;
    try {
        circle c = dynamic_cast<circle&>(s);
    }
    catch (exception& e) {
        cout << "could not convert it to circle: " << e.what() << endl;
    }
}