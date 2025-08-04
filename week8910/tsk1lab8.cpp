/*Task 1:
Design a class template named NumberStats that can store and calculate basic statistics (minimum, maximum,
and average) for a collection of numbers. The template should accept a data type (T) as a parameter. Implement
member functions for:
 Adding a number to the collection.
 Calculating the minimum, maximum, and average of the stored numbers.
Test your NumberStats class with different data types like int and double. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class numberstats {
private:
    vector<T> collection;
public:
    numberstats(vector<T> vec) : collection(vec) {}

    void additem(T val) {
        collection.push_back(val);
    }

    T maxval() {
        T maxv = 0;
        for (auto it : collection) {
            maxv = max(maxv, it);
        }
        return maxv;
    }

    T minval() {
        T minv = collection[0];
        for (auto it : collection) {
            minv = max(minv, it);
        }
        return minv;
    }

    T average_val() {
        T sum = 0;
        for (auto it : collection) {
            sum += it;
        }
        return (sum / collection.size());
    }

};

int main() {
    vector<double> vec = { 2.2,4.55,6.76 };
    numberstats<double> n(vec);
    n.additem(5.55);
    cout << n.maxval() << endl;
    cout << n.minval() << endl;
    cout << n.average_val() << endl;

}







/*
//for base case i.e recurrsion termiates smootly when only one element is remaining to be processed:
template <typename T>
void fun(T val) {
    cout << val << endl;
}

//actual function
template <typename T, typename... moretypes>
void fun(T val, moretypes... restvalues) {
    cout << val << " ";
    fun(restvalues...);
}

void addition(int a, int b) {
    cout << a + b;
}
//function pointer: points to its address and we can use it to pass to other functions

void (*funcptr)(int, int) = addition;

int main() {
    fun("hello", 67, 68.9, 'A');
    funcptr(2, 4);
    vector<int> vec{ 1,3,4,6,53,1,7 };
    sort(vec.begin(), vec.end());
    for (auto it : vec) {
        cout << it << " ";
    } cout << endl;

    reverse(vec.begin(), vec.end());
    cout << "reversed: " << endl;
    for (auto it : vec) {
        cout << it << " ";
    } cout << endl;



}*/

