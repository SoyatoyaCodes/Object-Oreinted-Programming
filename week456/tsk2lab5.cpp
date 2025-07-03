// Task 2: 
// Create a program to model temporary computer resources: 
// 1. Base Class: MemoryResource 
// a. Constructor prints "MemoryResource base allocated" 
// b. Destructor prints "MemoryResource base freed" 
// 2. Derived Class: NetworkBuffer (inherits from MemoryResource) 
// a. Constructor prints "NetworkBuffer derived allocated" 
// b. Destructor prints "NetworkBuffer derived freed" 
// 3. In main(): 
// a. Create a NetworkBuffer object inside a nested block 
// b. Observe what happens when the object goes out of scope 
// Q. Why does the MemoryResource constructor run before the NetworkBuffer constructor?
#include <iostream>
using namespace std;

class memresource {
public:
    memresource() {
        cout << "MemoryResource base allocated" << endl;
    }

    ~memresource() {
        cout << "MemoryResource base freed" << endl;
    }
};

class networkbuffer : public memresource {
public:
    networkbuffer() {
        cout << "NetworkBuffer derived allocated" << endl;
    }

    ~networkbuffer() {
        cout << "NetworkBuffer derived freed" << endl;
    }
};

int main() {
    {
        networkbuffer n1;
    }
}

//memresource constructor runs first because it is the base class and the networkbuffer class inherits from it.