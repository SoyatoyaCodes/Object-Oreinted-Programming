#include <iostream>
#include <vector>

using namespace std;

int height_mismatch_count(const vector<int>& heights) {
    const int max_height = 100; // assumption: btw 1-100
    vector<int> count(max_height + 1, 0);

    for (int h : heights) {
        count[h]++;
    }

    vector<int> expected;
    for (int h = 1; h <= max_height; ++h) {
        while (count[h]-- > 0) {
            expected.push_back(h);
        }
    }


    int mismatches = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if (heights[i] != expected[i]) {
            mismatches++;
        }
    }

    return mismatches;
}

int main() {
    vector<int> heights = { 3, 3, 4, 2, 1, 3 };
    int result = height_mismatch_count(heights);
    cout << "students out of place: " << result << endl;
    return 0;
}
