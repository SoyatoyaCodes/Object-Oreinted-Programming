//mountain peak problem
#include <iostream>
#include <vector>
using namespace std;

//generate total permutations of a given set of alphabets
void permutations(vector<int>& nums, int index, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    //we are making changes in the original vector here 
    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        permutations(nums, index + 1, ans);
        swap(nums[i], nums[index]);
    }
}

ostream& operator<<(ostream& os, vector<vector<int>>& ans) {
    for (int j = 0; j < ans.size(); j++) {
        for (int i = 0; i < ans[j].size(); i++) {
            os << ans[j][i];
        } os << " ";
    } os << endl;
    return os;
}

int main() {
    vector<int> v{ 1,2,3 };
    vector<vector<int>>answer;
    permutations(v, 0, answer);
    cout << answer;
}


//FIND MOUNTAIN PEAK LEETCODE
// int findpeak(vector<int>& v, int start, int end) {
//     //binary search algo here
//     while (start <= end) {
//         int mid = (start + end) / 2;
//         if (v[mid] > v[mid + 1] and v[mid] > v[mid - 1]) {
//             return mid;
//         }
//         else if (v[mid] > v[mid - 1]) {
//             //discard items below mid. go right
//             start = mid + 1;
//         }
//         else {//go left
//             end = mid - 1;
//         }
//     }
//     return -1; //if no peak is there
// }

// int main() {
//     vector<int> vec = { 0,3,2,5,4,4,2,0 };//ANS 5
//     cout << "peak is at index: ";
//     cout << findpeak(vec, 1, vec.size() - 2);

// }
