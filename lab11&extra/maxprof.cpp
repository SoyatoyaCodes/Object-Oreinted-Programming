#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//give max profit

int maxprof(vector<int>& v) {

    if (v.empty()) return 0;

    //variable initalization
    int bestbuy = v[0];
    int maxprofit = 0;
    int sellprice;

    for (int i = 0; i < v.size() - 1; i++) {
        sellprice = v[i + 1];//current index is sellprice
        int profit = 0;

        if (v[i] < bestbuy) {
            bestbuy = v[i];
        }

        profit = sellprice - bestbuy;
        if (profit > 0 and maxprofit < profit) {
            maxprofit = profit;
        }
    }

    return maxprofit;
}

// int maxprof(vector<int> v) {
//     //tedious
//     //tempvec for per index differences and one for the final vec from where the max will be found
//     vector<int> temp;
//     vector<int> final;
//     //assume bestbuy is current index
//     for (int i = 0; i < v.size(); i++) {
//         int bestbuy = v[i];
//         for (int j = i + 1; j < v.size(); j++) {

//             if (v[j] > bestbuy) {
//                 temp.push_back(v[j] - bestbuy);
//             }
//         }

//         if (!temp.empty()) {
//             final.push_back(*max_element(temp.begin(), temp.end()));
//         }
//         temp.clear();
//     }

//     return *max_element(final.begin(), final.end());
// }

int main() {
    vector<int> v = { 7,1,5,3,6,4 };
    cout << maxprof(v); //5  (6-1)
}