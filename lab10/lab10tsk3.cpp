#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class selectsort {
    void operator()(vector<T>& arr) const {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                swap(arr[i], arr[min_index]);
            }
        }
    }
};


int main() {
    vector<int> nums = { 7, 14, 5, 56, 79, 1 };

    selectsort<int> sorter;
    sorter(nums);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
