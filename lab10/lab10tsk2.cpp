//insertionsort code
#include <iostream>
#include <vector>
using namespace std;

class performinsertionsort {
private:
    vector<int> v;
public:
    performinsertionsort(vector<int>& vec) : v(vec) {}
    void operator()() {
        //insertionsort logic
        for (int i = 1; i < v.size(); i++) {
            int temp = v[i];
            int j = i - 1;
            while (j >= 0 and v[j] > temp) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = temp;

        }

        for (auto it : v) {
            cout << it << " ";
        }
    }
};

int main() {
    vector<int> v = { 2,4,56,3,2,5,1 };
    performinsertionsort p(v);
    p();
}
