// Task 4:  
// You are required to implement a program that demonstrates the usage of function pointers along with different 
// algorithms provided by the C++ Standard Library's algorithm library. The program will perform various operations 
// on a list of integers based on user input.  
// Implement the following functions to perform various operations on a list of integers:  
//  sortArray: Sorts the elements in the array in non-decreasing order.  
//  reverseArray: Reverses the order of the elements in the array.  
//  rotateArray: Rotates the order of the elements in the array.  
//  findMinElement: Finds the minimum element in the array.  
//  findMaxElement: Finds the maximum element in the array.  
//  countOccurrences: Counts the number of occurrences of a specific value in the array.  
// Define a function custom_algorithm that takes a vector of integers and a function pointer as arguments. This 
// function will apply the operation specified by the function pointer to the vector of integers.  
// In the main function, demonstrate the usage of function pointers by calling the custom_algorithm function 
// with different function pointers corresponding to the operations mentioned above.  
// Hints:  
// Import: #include<algorithm> and use following built-in functions  
//  Sort: std::sort(arr.begin(), arr.end());  
//  Reverse: std::reverse(arr.begin(), arr.end());  
//  Rotatet: std::rotate(arr.begin(), arr.begin() + 1, arr.end());  
//  MinElement= std::min_element(arr.begin(), arr.end());  
//  MaxElement= std::max_element(arr.begin(), arr.end());Count= std::count(arr.begin(), arr.end(), value);

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortarray(vector<int>& vec) {
    cout << "sorted array: ";
    sort(vec.begin(), vec.end());
    return vec;
}

vector<int> reversearr(vector<int>& vec) {
    cout << "reversed array: ";
    reverse(vec.begin(), vec.end());
    return vec;
}

vector<int> rotatearr(vector<int>& v) {
    cout << "rotated array: ";
    rotate(v.begin(), v.begin() + 1, v.end());
    return v;
}
//overloaded operator for printing vectors
ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v) {
        os << i << " ";
    }
    os << endl;
    return os;
}

int minelementarr(vector<int>& v) {
    cout << "min element: " << endl;
    return *min_element(v.begin(), v.end());
}

int maxelementarr(vector<int>& v) {
    cout << "max element: ";
    return *max_element(v.begin(), v.end());
}

int countoccurances(vector<int>& v) {
    int val;
    cout << "enter a value to count occurances: ";
    cin >> val;
    return count(v.begin(), v.end(), val);
}
template<typename T>
void custom_algorithm(vector<int>& vec, T(*funptr)(vector<int>& v)) {
    cout << funptr(vec) << endl;
}

int main() {
    vector<int> vec = { 3,4,5,6,7,1 };
    //function pointer vectors
    vector<int (*)(vector<int>&)> func{ countoccurances,maxelementarr,minelementarr };
    vector<vector<int>(*)(vector<int>&)> func2{ sortarray,rotatearr,reversearr };

    for (auto it : func) { custom_algorithm(vec, it); }

    for (auto it : func2) { custom_algorithm(vec, it); }


}