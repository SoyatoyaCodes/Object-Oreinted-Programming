#include <iostream>
#include <vector>
#include <string>
#include <functional> 

using namespace std;

class Student {
public:
    string name;
    double gpa;

    Student(string studentName, double studentGpa) {
        name = studentName;
        gpa = studentGpa;
    }

    void display() const {
        cout << name << " (" << gpa << ")" << endl;
    }
};

struct comparename {
    bool operator()(const Student& a, const Student& b) const {
        return a.name < b.name;
    }
};

struct comparegpades {
    bool operator()(const Student& a, const Student& b) const {
        return a.gpa > b.gpa;
    }
};

template <typename T>
class genericsorter {
public:
    void insertionSort(vector<T>& items, function<bool(const T&, const T&)> cmp) {
        for (size_t i = 1; i < items.size(); ++i) {
            T current = items[i];
            int j = i - 1;
            while (j >= 0 && cmp(current, items[j])) {
                items[j + 1] = items[j];
                j--;
            }

            items[j + 1] = current;
        }
    }
};

int main() {
    vector<Student> students = {
        Student("Soha", 3.8),
        Student("Ali", 3.1),
        Student("Roha", 3.9),
        Student("Zoya", 4.0)
    };

    genericsorter<Student> sorter;

    vector<Student> byname = students;
    sorter.insertionSort(byname, comparename());
    cout << "Sorted by Name:" << endl;
    for (const auto& s : byname) s.display();

    vector<Student> bygpa = students;
    sorter.insertionSort(bygpa, comparegpades());
    cout << "\nSorted by GPA (descending):" << endl;
    for (const auto& s : bygpa) s.display();

    return 0;
}
