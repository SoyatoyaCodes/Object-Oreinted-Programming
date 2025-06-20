// Define a class DynamicArray that contains: 
// • A dynamically allocated integer array. 
// • A constructor to initialize the array with a given size. 
// • A method set(int index, int value) to set a value at a specific index. 
// • A method get(int index) to retrieve a value at an index. 
// • A default copy constructor (compiler-generated) to demonstrate shallow copying. 
// • A manual deep copy constructor that allocates new memory and copies elements individually. 
// In the main function: 
// 1. Create an object and fill it with values. 
// 2. Copy it using the default copy constructor (shallow copy). 
// 3. Modify the original object and observe the effect on the copied object. 
// 4. Implement a deep copy constructor and repeat step 3 to confirm that the copied object is 
// independent. 
// Question: Why does modifying the original object affect the shallow copy but not the deep copy?
#include <iostream>
#include <stdexcept>
using namespace std;
class dynamicarray {
private:
    int* dyn_arr;
    int s; //dyn array initalization??
public:
    dynamicarray(int size) {
        dyn_arr = new int[size];
        s = size;
    }

    int size() const {
        return s;
    }

    //default constructor
    dynamicarray() = default;
    //deep copy constructor

    dynamicarray(const dynamicarray& obj) { //If we don’t pass by reference, the compiler will try to make a copy, which calls the same constructor again, infinite loop
        this->s = obj.s;
        this->dyn_arr = new int[s];
        for (int i = 0; i < s; i++) {
            this->dyn_arr[i] = obj.dyn_arr[i];
        }
    }
    ~dynamicarray() {
        delete[] dyn_arr;
    }

    void setval(int index, int value) {
        if (index < s && index >= 0) {
            dyn_arr[index] = value;
        }
        else {
            throw invalid_argument("index is out of bounds");
        }
    }

    int getval(int index) {
        if (index >= 0 && index < s) {
            return dyn_arr[index];
        }
        else {
            throw invalid_argument("invaild index provided. no value can be returned");
        }
    }
};

int main() {
    dynamicarray obj(6);

    //for(auto& it : obj.dyn_arr){} does not work because range based for loop needs a container and we want to interate over raw ptr

    for (int i = 0; i < obj.size(); i++) {
        obj.setval(i, i * 10);
    }
    //shallow copy
    dynamicarray obj3 = obj;
    obj3.setval(2, 3);
    cout << "shallow copy affect on obj" << endl;
    cout << obj.getval(2);

    //deep copy constructor called
    dynamicarray obj2(obj);

}