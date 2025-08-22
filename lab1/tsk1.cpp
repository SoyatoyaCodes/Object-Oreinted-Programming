// Design and implement a class to store student data.  
// 1. Define the necessary attributes for each student (id, name, CGPA). Define a public field called courses that stores each 
// course name the student is enrolled in. 
// 2. Define a custom default constructor that takes inputs from the user and set the attributes accordingly.  
// 3. Define a parameterized constructor as well, that takes arguments to set the attributes of each student.  
// 4. Display the ‘courses’ of a student by accessing the attribute directly in the main function. Then figure out how to 
// display the other private attributes.

#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class storedata {
private:
    string name;
    int id;
    double cgpa;
public:
    vector<string> courses;
    //parameterized constructor
    storedata(string n, double c, int id, const vector<string>& course) : name(n), cgpa(c), id(id), courses(course) {}
    //default
    storedata() {
        cout << "enter your information here!!" << endl;
        cout << "your name: ";
        cin >> name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush backslash n
        cout << "student id: ";
        cin >> id;
        cout << "cgpa: ";
        cin >> cgpa;

        int num;
        cout << "how many courses are you enrolled in??" << endl;
        cin >> num;
        courses.resize(num);

        for (int i = 0; i < num; i++) {
            string course;
            cout << "enter " << i + 1 << " course" << endl;
            cin >> course;
            courses.push_back(course);
        }
    }

    void setname(string n) {
        this->name = n;
    }
    void set_id(int i) {
        this->id = i;
    }

    void set_cgpa(double c) {
        this->cgpa = c;
    }

    string getname() {
        return name;
    }

    int get_id() {
        return id;
    }

    double get_cgpa() {
        return cgpa;
    }

};

//outstream overload 
ostream& operator<<(ostream& os, storedata& s) {
    for (string it : s.courses) {
        cout << it << " ";
    }
    cout << endl;
    return os;
}

int main() {
    storedata student1;
    for (string it : student1.courses) {
        cout << it << " ";
    }
    cout << endl;
    storedata student2("soha", 3.8, 7458, { "linear algebra", "dsa", "digital logic design" });
    //overloaded operator check
    cout << "student2 courses output: " << endl;

    cout << student2;
    cout << student2.getname() << endl;
    cout << student2.get_cgpa();

}