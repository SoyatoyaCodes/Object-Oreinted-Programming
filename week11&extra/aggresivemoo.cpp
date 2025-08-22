#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canplaceCows(vector<int>& v, int c, int mid) {

    int cowPlaced = 1; //we start with 1 cow
    int prevpos = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] - prevpos >= mid) {
            cowPlaced++;
            prevpos = v[i];
        }
    }
    return cowPlaced >= c; //we can place atleast c cows
}

int maximin_dis(vector<int>& v, int c) {
    sort(v.begin(), v.end());//for bool func call
    //range (1 till maxval-minval)
    int start = 1;
    int end = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
    int ans = -1;
    //binary search algo
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (canplaceCows(v, c, mid)) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v = { 1,2 };
    int cows = 0;
    cout << maximin_dis(v, cows);
}