// Task 3: 
// Implement a Point class in C++ that supports basic 2D point operations using operator 
// overloading and calculates the Euclidean distance from the origin. 
// 1. Define a Point Class: 
// o Private members: x and y (integers). 
// o Public constructor: Point(int x = 0, int y = 0). 
// 2. Overload Operators: 
// o + Operator: Adds two Point objects (e.g., Point(1,2) + Point(3,4) = Point(4,6)). 
// o - Operator: Subtracts two Point objects. 
// o * Operator: Multiplies a Point by an integer scalar (e.g., Point(2,3) * 3 = Point(6,9)). 
// o == Operator: Checks if two Point objects are equal. 
// o = Operator: Assigns one Point to another. 
// 3. Friend Function for Length: 
// o Implement a friend function calculateLength that returns the Euclidean distance of 
// the Point from the origin (0,0)
// o Use sqrt() from <cmath> for the calculation. 
// 4. Output Formatting: 
// o Overload << to print points as Point(x, y). 
#include <iostream>
using namespace std;
#include <cmath>

class point {
private:
    int x;
    int y;
public:
    point() : x(0), y(0) {}
    point(int x, int y) : x(x), y(y) {}

    //overloaded operators
    point operator+(point& p2) {
        point p;
        p.x = this->x + p2.x;
        p.y = this->y + p2.y;
        return p;
    }
    point operator-(point& p2) {
        point p;
        p.x = this->x - p2.x;
        p.y = this->y - p2.y;
        return p;
    }

    point& operator*(int scaler) {
        this->x = x * scaler;
        this->y = y * scaler;
        return *this;

    }

    bool operator==(point& p) {
        if (this->x == p.x && this->y == p.y) {
            return true;
        }
        else {
            return false;
        }
    }

    point& operator=(point& p) {
        if (this->x == p.x && this->y == p.y) {
            return *this;
        }
        else {
            this->x = p.x;
            this->y = p.y;
        }
        return *this;
    }

    friend int calclength(point& p);
    friend ostream& operator<<(ostream& os, point& p);

};

int calclength(point& p) {
    p.x = p.x * p.x;
    p.y = p.y * p.y;

    return sqrt(p.x + p.y);
}

ostream& operator<<(ostream& os, point& p) {
    os << " ( " << p.x << " , " << p.y << " ) ";
    return os;
}

int main() {

    point p(3, 4);
    point p1(5, 7);
    p * 3;
    cout << p << endl;
    point newp = (p + p1);
    cout << newp << endl;
    p = p1;
    cout << p << endl;
    point po = p1 * 45;
    cout << po << endl;

}