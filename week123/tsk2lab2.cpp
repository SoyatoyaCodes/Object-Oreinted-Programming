// Extend the DynamicArray class by implementing: 
// • An overloaded assignment operator (operator=) that performs a deep copy. 
// In the main function: 
// 1. Create two DynamicArray objects and use operator= to assign one object to another. 
// 2. Modify one of them and verify that the other remains unchanged. 
// Note: Put a self-assignment check to prevent the data deleting itself during copying. 

#include <iostream>
#include <stdexcept>
using namespace std;
class dynamicarray {
private:
    int* dyn_arr;
    int s;
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

    //assignment operator
    dynamicarray& operator=(const dynamicarray& obj) {
        cout << "overloaded = called" << endl;

        //checker
        if (this == &obj);
        return *this;

        //else delete the current obj's array
        delete[] this->dyn_arr;

        //deep copy
        this->s = obj.s;
        this->dyn_arr = new int[s];
        for (int i = 0; i < s; i++) {
            this->dyn_arr[i] = obj.dyn_arr[i];
        }
        return *this;
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

    for (int i = 0; i < obj.size(); i++) {
        obj.setval(i, i * 10);
    }

    // dynamicarray ob2 = obj; //rn shallow copy is created. because at the moment of ob2 initialization, we are assigning
    dynamicarray ob2(6);
    ob2 = obj;//now assignment operator overload is called

    ob2.setval(2, 57);
    cout << ob2.getval(2) << endl;
    cout << "original obj value remians unchanged " << obj.getval(2) << endl;


}