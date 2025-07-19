// Task 1: 
// Employees and Salary 
// Create an abstract class Employee with properties name and salary and a pure virtual method 
// calculateBonus(). Create two classes Manager and Programmer that extend Employee and 
// implement the calculateBonus() method. 
// Create an abstract class IPromotable with a pure virtual method promote(double newSalary) 
// and implement this abstract class in both Manager and Programmer

#include <iostream>
using namespace std;
//abstract classes
class employee {
protected:
    string name;
    float salary;
public:
    employee(string n, float s) : name(n), salary(s) {}

    virtual void calculatebonus() = 0; //pure virtual method
};

class ipromotable {
public:
    virtual void promote(double salary) = 0;
};

//implementations
class manager : public employee, public ipromotable {
public:
    manager(string n, float s) : employee(n, s) {}

    void calculatebonus() override {
        cout << "the new bonus is: " << salary * 0.04 << endl; //the bonus is 4 percent of the total salary
    }

    void promote(double newsalary) override {
        cout << name << " got promoted from " << salary << " to " << newsalary << endl;
        salary = newsalary;
    }
};

class programmer : public employee, public ipromotable {
public:
    programmer(string n, float s) : employee(n, s) {}
    //lets say bonus is 30 percent of any salary
    void calculatebonus() override {
        cout << "the new bonus is: " << salary * 0.3 << endl;
    }
    void promote(double newsalary) override {
        cout << name << " got promoted from " << salary << " to " << newsalary << endl;
        salary = newsalary;
    }
};

int main() {
    manager m("soha", 5000);
    programmer p("soha again :/", 595896);
    m.promote(5864);
    m.calculatebonus();
    p.promote(8954986783);
    p.calculatebonus();
}