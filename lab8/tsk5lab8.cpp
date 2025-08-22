// Task 5: 
// Write a function int findpos(void *A, int n, ftype fp), where A is a generic array of size n and 
// f
//  type is a function pointer that takes an array and size as its argument and apply the algorithm to find the position 
// based on the function. 
#include <iostream>
using namespace std;

typedef int (*ftype)(void*, int);

int findpos(void* A, int n, ftype fp) {
    return fp(A, n);
}

int findMaxPos(void* arr, int n) {
    int* a = (int*)arr;
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int nums[] = { 3, 7, 2, 9, 5 };
    int index = findpos(nums, 5, findMaxPos);
    cout << "Position: " << index << endl;
    return 0;
}
