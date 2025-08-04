// Task 6: 
// Create a function template named sumAll that accepts a variable number of arguments using variadic templates 
// and returns the sum of all arguments passed to it. 
// The function should work with any numeric type (e.g., int, float, double, long, etc.). 
// Make sure the return type is correctly deduced based on the input. 
// Write a main function to test sumAll with different combinations of data types and argument counts

#include <iostream>
using namespace std;

template<typename T>
T sumall(T val) {
    return val;
}

template<typename T, typename...diff_dtypes> //how tobdeduce correct reutn type?
auto sumall(T val, diff_dtypes... restvals) -> decltype(val + sumall(restvals...)) {
    return val + sumall(restvals...);
}

//idk the issue here
int main() {
    //cout << sumall(1, 2, 3) << endl;             // Outputs: 6
    // cout << sumall(1.5, 2, 3.5) << endl;         // Outputs: 7
    // cout << sumall(10, 20.5f, 30L, 40.0) << endl;// Outputs: 100.5
}

