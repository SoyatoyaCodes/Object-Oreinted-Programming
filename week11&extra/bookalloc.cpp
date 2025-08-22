#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; //TIME COMPLEXITY : O(LOG(RANGE)* N) WHERE RANGE = END-START
//isvalid checker: if all the students can get pages within the mid val range or not
bool isvalid(vector<int>& v, int mid_maxpages, int students) {
    int stu = 1;
    int pages = 0;

    for (int i = 0; i < v.size(); i++) {
        //important check: if any of the v[i] values are > mid val then there is no way for it to be a valid minimum maximum
        if (v[i] > mid_maxpages) {
            return false;
        }

        if (pages + v[i] <= mid_maxpages) {
            pages += v[i];
        }
        else {
            stu++;
            pages = v[i];
        }
    }

    if (stu > students) {
        return false;
    }
    else return true;

}


int allocatebooks(vector<int>& v, int stu) {
    if (stu > v.size()) {
        return -1;
    }
    //calculating the sum of all the pages to find the range
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i]; //range becomes 0 till sum
    }

    //cool to note: start!= 0 but instead max element in the array
    // Lower bound must be the largest single book (max_element) since no student can get less than that book's pages.
    // Lower bound = largest single book (since at least one student must take it)
    // Upper bound = sum of all pages (case where one student gets all books)

    //binary search code
    int start = *max_element(v.begin(), v.end());
    int end = sum;
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isvalid(v, mid, stu)) {
            end = mid - 1; //go left for a better answer
            ans = mid;
        }
        else {
            start = mid + 1; //go right
        }
    }
    return ans;

}

int main() {
    vector<int> vec = { 15,17,20 }; //4 books and each element represents number of pages
    //number of students who will get the books in contiguous manner
    int students = 2;
    cout << allocatebooks(vec, students);
}

// The question asks for the minimum possible “maximum pages” a student has to take.

// Since a student must take whole books, the minimum maximum can never be
//  smaller than the largest single book. That’s why start = max_element(arr)
//  is correct.

