// Task 1: 
// Create a simple program with two classes: 
// 1. Person Class 
// a. Has two protected member variables: name (string) and age (int). 
// b. Add a constructor that sets name and age when a Person object is created. 
// 2. Student Class (inherits publicly from Person) 
// a. Adds a new member variable: studentID (int). 
// b. Add a constructor that initializes: 
// i. 
// The Person part (name and age) 
// ii. 
// The studentID 
// c. Add a display()that prints: 
// i. 
// "Name: [name], Age: [age], ID: [studentID]" 
// 3. Test the Program 
// a. In main(), create a Student object 
// b. Call the display() function to show all details. 
#include <iostream>
using namespace std;
class person {
protected:
    string name;
    int age;
public:
    person(string n, int a) : name(n), age(a) {}


};

class student : public person {
    int studentid;
public:
    student(string n, int a, int id) : person(n, a), studentid(id) {}

    void display() {
        cout << "[NAME]: " << name << " [AGE]: " << age << " [ID]: " << studentid << endl;
    }

};

int main() {
    student first("soha", 18, 478975976);
    first.display();

}