// Create a class InstanceCounter with: 
// 1. A private static member variable count that tracks the number of instances of the class. 
// 2. A constructor that increments count whenever a new object is created. 
// 3. A public static method getCount() that returns the current 
// value of count. 
// In the main function, create multiple objects of the class, and use 
// getCount() method to print how many objects have been created. 

#include <iostream>
using namespace std;

class instancecounter {
private:
    inline static int count = 0;
public:
    instancecounter() {
        count++;
    }
    static int getcount() {
        return count;
    }
};

int main() {
    instancecounter c1;
    instancecounter c2;
    instancecounter c3;
    instancecounter c4;

    cout << "total instances creacted " << instancecounter::getcount();

}