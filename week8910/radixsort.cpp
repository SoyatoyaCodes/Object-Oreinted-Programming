#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//time complexity: O(n log(max_val))
/*
n= number of elements
k= digits in max val
b = base provided

(n +2b)(k) where k is logn with base 10 always since maxval/placeval and placeval keeps on
multiplying with 10

SPACE COMPLEX
BUCKET OF SIZE BASE AND EACH HOLDS N ITEMS IE (N+B)
SO O(N)
*/


//TYPICAL SORT WITHOUT COMPARISION SORT
vector<vector<int>> createbuckets(int base) {
    vector<vector<int>> buckets(base); //creates "base" buckets
    return buckets;
}

void radixsort(vector<int>& v, int base) {

    vector<vector<int>> buckets = createbuckets(base);
    int placeval = 1;
    int max_value = *max_element(v.begin(), v.end());

    while ((max_value / placeval) > 0) {

        //emptying internal vectors here
        for (int i = 0; i < buckets.size(); i++) {
            buckets[i].clear();
        }
        for (int i = 0; i < v.size(); i++) {  //one iteration of storing in buckets
            int digit = (v[i] / placeval) % base;
            buckets[digit].push_back(v[i]);
        }
        //flatten it to an array
        v.clear(); //empty it first
        for (int i = 0; i < buckets.size(); i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                v.push_back(buckets[i][j]);
            }
        }
        placeval *= 10;
    }
}

int main() {
    vector<int> v = { 23, 567, 189, 1 };
    int b = 10;
    radixsort(v, b);
    for (auto it : v) {
        cout << it << " ";
    }
}

//NOTE: buckets.clear(); //will it clear the vec of vec along with size!! noo