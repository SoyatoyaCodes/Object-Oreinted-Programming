// Task 3:  
// In this lab task, you will develop a program to manage employee records. The program should provide 
// functionalities to add, delete, and display employee records, as well as to perform various operations 
// on the records using functors, function pointers, and lambdas with STL. 
// Task Instructions: 
// Define a class named Employee with the following attributes: 
// • Employee ID (int) 
// • Name (std::string) 
// • Department (std::string) 
// • Salary (double) 
// Implement a class named EmployeeManager to manage employee records. This class should have the 
// following functionalities: 
// 1. Add a new employee record. 
// 2. Delete an existing employee record by ID. 
// 3. Display all employee records. 
// 4. Sort employee records based on different criteria using functors, function pointers, or lambdas. 
// 5. Find employees with salaries above a certain threshold using a lambda function. 
// 6. Calculate the average salary of all employees. 
// 7. Customize display of employee records by providing different display options using function pointers. 
// Note: Use std::map to store employee records. 
// Task Requirements: 
// 1. Implement the Employee class with the specified attributes. 
// 2. Implement the EmployeeManager class with the specified functionalities. 
// 3. Use functors, function pointers, or lambdas where appropriate to perform sorting, filtering, and 
// 4. customization of display. 
// 5. Test the program with various scenarios to ensure correctness and functionality

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Employee {
public:
    int id;
    string name;
    string department;
    double salary;
    Employee() {}
    Employee(int i, const string& n, const string& d, double s)
        : id(i), name(n), department(d), salary(s) {
    }
};

class EmployeeManager {
private:
    map<int, Employee> employees;
public:
    void addEmployee(const Employee& emp) {
        employees[emp.id] = emp;
        cout << "Employee added: " << emp.name << "\n";
    }
    void deleteEmployee(int id) {
        if (employees.erase(id)) {
            cout << "Employee with ID " << id << " deleted.\n";
        }
        else {
            cout << "Employee ID not found.\n";
        }
    }
    void displayEmployees(void (*displayFunc)(const Employee&)) const {
        for (const auto& pair : employees) {
            displayFunc(pair.second);
        }
    }
    void sortEmployees(function<bool(const Employee&, const Employee&)> comp) const {
        vector<Employee> empList;
        for (auto& p : employees) empList.push_back(p.second);
        sort(empList.begin(), empList.end(), comp);
        cout << "\nSorted Employees:\n";
        for (auto& e : empList) {
            cout << e.id << " " << e.name << " " << e.department << " $" << e.salary << "\n";
        }
    }
    void findHighSalary(double threshold) const {
        cout << "\nEmployees with salary > " << threshold << ":\n";
        for_each(employees.begin(), employees.end(),
            [threshold](const auto& p) {
                if (p.second.salary > threshold)
                    cout << p.second.name << " $" << p.second.salary << "\n";
            });
    }
    void calculateAverageSalary() const {
        if (employees.empty()) {
            cout << "No employees available.\n";
            return;
        }
        double sum = accumulate(employees.begin(), employees.end(), 0.0,
            [](double acc, const auto& p) { return acc + p.second.salary; });
        double avg = sum / employees.size();
        cout << "Average salary = $" << avg << "\n";
    }
};

void displayBasic(const Employee& e) {
    cout << "ID: " << e.id << " Name: " << e.name << "\n";
}

void displayDetailed(const Employee& e) {
    cout << "ID: " << e.id << " Name: " << e.name
        << " Dept: " << e.department << " Salary: $" << e.salary << "\n";
}

int main() {
    EmployeeManager manager;
    manager.addEmployee(Employee(101, "Alice", "HR", 5000));
    manager.addEmployee(Employee(102, "Bob", "IT", 7000));
    manager.addEmployee(Employee(103, "Charlie", "Finance", 6000));
    manager.addEmployee(Employee(104, "Diana", "IT", 8000));

    cout << "\n--- Basic Display ---\n";
    manager.displayEmployees(displayBasic);

    cout << "\n--- Detailed Display ---\n";
    manager.displayEmployees(displayDetailed);

    manager.sortEmployees([](const Employee& a, const Employee& b) {
        return a.name < b.name;
        });

    manager.sortEmployees([](const Employee& a, const Employee& b) {
        return a.salary > b.salary;
        });

    manager.findHighSalary(6000);
    manager.calculateAverageSalary();
    manager.deleteEmployee(102);

    cout << "\n--- Employees after Deletion ---\n";
    manager.displayEmployees(displayDetailed);

    return 0;
}
