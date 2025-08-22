//shellsort algo
//Task 4: 
//Implement a generic function shell_sort that takes in an std::vector<T>& and sorts it (in place) using shell sort
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
template<typename T>
void shellsort(vector<T>& v) {

    for (int gap = v.size() / 2; gap > 0; gap /= 2) {
        cout << "Gap is " << gap << endl;
        for (int i = gap; i < v.size(); i++) {
            cout << "now dealing with i" << i << ", ";
            int count = 0;
            for (int j = i - gap; j >= 0; j = j - gap) {
                cout << "j is " << i << count++ << " ";
                if (v[j + gap] < v[j]) {
                    cout << "!!just swapped " << j + gap << " with " << j << "!! ";
                    swap(v[j + gap], v[j]);
                }
            } cout << endl;
        }
    }
}

template <typename T>
void printvec(vector<T>& v) {

    for (auto it : v) {
        cout << it << " ";
    }cout << endl;
}

int main() {

    vector<double> v1 = { 12.6,34.8,54.99,2.12,3.9 };
    vector<int>v = { 12,56,1,98,74,11 };
    vector<string> v3 = { "soha", "starfish" , "cookie", "awesome", "unicorn", "trees" };

    auto t = make_tuple(ref(v1), ref(v), ref(v3));
    //lambda function:
    auto sort = [](auto&... vecs) { (shellsort(vecs), ...); };

    apply(sort, t);

    auto print = [](auto&...pack) {
        (printvec(pack), ...);
        };

    apply(print, t);

}