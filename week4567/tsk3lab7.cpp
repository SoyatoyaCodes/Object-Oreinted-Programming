// 1) No accessors and mutators are allowed to be used.  
// 2) The Display() function in ConsultantManager should be capable of displaying the values of all the data 
// members declared in the scenario (name, code, yearsOfExperience, noOfTeams) without being 
// able to alter the values.  
// 3) The main function should contain only three program statements which are as follows:  
// In the first statement, create object of ConsultantManager and pass the values for all the data members: 
// ConsultantManager obj("Ali",”S-123”,17,5);  
// In the second statement, call the Display() function.  
// In the third statement, return 0.  
// 4) All the values are required to be set through constructors’ parameters. 

#include <iostream>
#include <string>
using namespace std;
//inheriting virtually like virtual public base. helps 
class employee {
protected:
    string name;
    string code;
public:
    employee(string n, string c) : name(n), code(c) {}
    virtual ~employee() {}
};

class consultant : virtual public employee {
protected:
    int yearexperience;
public:
    consultant(string n, string c, int yoe) : employee(n, c), yearexperience(yoe) {}

};

class manager : virtual public employee {
protected:
    int noofteams;
public:
    manager(string n, string c, int no) : employee(n, c), noofteams(no) {}

};

class consultantmanager : public consultant, public manager {
public:
    consultantmanager(string n, string c, int yoe, int numbofteams) : employee(n, c), consultant(n, c, yoe), manager(n, c, numbofteams) {}
    void display() const {
        cout << "name: " << name << endl;
        cout << "code: " << code << endl;
        cout << "years of experience: " << yearexperience << endl;
        cout << "number of teams: " << noofteams << endl;
    }
};

int main() {
    consultantmanager person("cool guy", "3644", 12, 16);
    person.display();


}

//also, otherwise let say base* obj = new consultmanag. only base destructor will be called and rest is mem leak(3 objs)