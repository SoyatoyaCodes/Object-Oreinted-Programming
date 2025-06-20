// Create a class Circle with: 
// • A private member radius (float). 
// • Public methods:  
// o setRadius(float r) to set the value of radius. 
// o getRadius() to return the value of radius. 
// o circumference() to calculate and return the 
// circumference. 
// In main, create a Circle object, set the radius using setRadius(), and display its circumference.

#include <iostream>
using namespace std;

class circle {
private:
    float radius;
public:

    void setradius(float r) {
        radius = r;
    }

    float getradius() {
        return radius;
    }

    float circumference() {
        //2pir
        return 2 * 3.14 * radius;
    }
};

int main() {
    circle c;
    c.setradius(4.5);
    cout << c.circumference();
}