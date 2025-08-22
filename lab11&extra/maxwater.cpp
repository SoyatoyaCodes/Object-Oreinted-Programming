#include <iostream>
#include <vector>
using namespace std;

//optimal solution: 2 pointer approach
int mostwater(vector<int>& v) {
    //move the shortest one towards the middle
    //you start from edges and move inwards
    int left = 0;
    int right = v.size() - 1;
    int height = 0;
    int distance = 0;
    int maxarea = 0;
    //distance = right-left and height= min of left and right values
    while (left < right) {
        height = min(v[left], v[right]);
        distance = right - left;
        maxarea = max(maxarea, height * distance);

        if (v[left] < v[right]) {
            left++;
        }
        else {
            right--;
        }

    }
    return maxarea;
}

// //brute force appraoch o(n^2)
// int mostwater(vector<int>& v) {
//     int length;
//     int maxarea = 0;

//     for (int i = 0; i < v.size(); i++) {
//         int distance = 0;
//         //first: v[i]; //compare this with all the rest in front of it
//         for (int j = i + 1; j < v.size(); j++) {
//             length = min(v[i], v[j]);
//             distance++; //distances between the values at their respective indexes
//             maxarea = max(maxarea, distance * length);
//         }
//     }
//     return maxarea;
// }

int main() {
    vector<int> height{ 1,8,6,2,5,4,8,3,7 };
    //max is 49
    cout << mostwater(height);
}