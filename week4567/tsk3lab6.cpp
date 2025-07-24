// Task 3:  
// Percentage Problem using Abstract Classes 
// We have to calculate the percentage of marks obtained in three subjects (each out of 100) by student A and 
// in four subjects (each out of 100) by student B. Create an abstract class 'Marks' with a pure virtual 
// method 'getPercentage()'. It is inherited by two other classes 'A' and 'B', each having a method 
// with the same name that returns the percentage of the students. 
// The constructor of student A takes the marks in three subjects as its parameters and the marks in four 
// subjects as its parameters for student B. Create an object for each of the two classes and print the 
// percentage of marks for both the students. 

#include <iostream>
using namespace std;

class marks {
public:
    virtual double getpercentage() = 0;
    virtual ~marks() {};
};

class A : public marks {
private:
    //3 subjects
    double s1, s2, s3;
public:
    A(double sub1, double sub2, double sub3) : s1(sub1), s2(sub2), s3(sub3) {};

    double getpercentage() override {
        static int totalmarks = 300;
        double obtained = s1 + s2 + s3;
        return (obtained / totalmarks) * 100;
    }
};

class B : public marks {
private:
    //4 subjects
    double s1, s2, s3, s4;
public:
    B(double sub1, double sub2, double sub3, double sub4) : s1(sub1), s2(sub2), s3(sub3), s4(sub4) {};

    double getpercentage() override {
        static int totalmarks = 400;
        double obtained = s1 + s2 + s3 + s4;
        return (obtained / totalmarks) * 100;
    }
};

int main() {
    //without using interface/abstract class:
    A student1(58, 88, 97);
    B student2(99, 98, 66, 88);
    cout << "1st student percentage " << student1.getpercentage() << endl;
    cout << "2st student percentage " << student2.getpercentage() << endl;
    //using the interface
    cout << "using polymorphism property: " << endl;

    // marks* student = new A(58, 88, 97);
    // student->getpercentage();
    // delete student;
    // student = new B(99, 98, 66, 88);
    // student->getpercentage();
    // delete student;

    //more clean way to do this: array of marks pointers
    marks* arr[2];
    arr[0] = new A(99, 100, 60);
    arr[1] = new B(98, 78.5, 80, 100);
    for (marks*& it : arr) {
        it->getpercentage();
        delete it;
    }

    return 0;


}