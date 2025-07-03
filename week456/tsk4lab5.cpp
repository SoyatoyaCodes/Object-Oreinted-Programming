
// Design a class hierarchy to model zoo animals with basic behaviors and feeding requirements: 
// 1. Base Class Animal 
// a. Properties: 
// i. 
// name (string) 
// ii. 
// age (int ≥ 0) 
// b. Methods: 
// i. 
// virtual void makeSound() (default: "makes a generic animal sound!") 
// ii. 
// 2. Subclasses 
// virtual void displayInfo() (shows name and age) 
// a. Lion (inherits Animal): 
// i. 
// Overrides makeSound() to print "[name] roars loudly!" 
// ii. 
// Overrides displayInfo() to prefix output with "Lion" 
// b. Snake (inherits Animal): 
// i. 
// Adds property: venomous (bool) 
// ii. 
// iii. 
// Overrides makeSound() to print "[name] hisses softly!" 
// Overrides displayInfo() to show venom status 
// c. Monkey (inherits Animal): 
// i. 
// Make your own implementation

#include <iostream>
#include <stdexcept>
using namespace std;

class animal {
protected:
    string name;
    int age;
public:
    animal(string n, int a) : name(n) {
        if (a < 0) {
            throw invalid_argument("wrong age input made!");
        }

        age = a;
    }
    virtual void makesound() {
        cout << "makes a generic animal sound!" << endl;
    }


    virtual void display_info() {
        cout << "name: " << name << " age: " << age << endl;
    }
};

class lion : public animal {
public:
    lion(string n, int a) : animal(n, a) {}
    void makesound() override {
        cout << name << " roars loudly!!" << endl;
    }

    void displayinfo() {
        cout << "name 🦁: " << name << " age: " << age << endl;
        cout << "All hail king " << name << endl;
    }
};

class snake : public animal {
private:
    bool venomous;
public:
    snake(string n, int a, bool v) : animal(n, a), venomous(v) {}
    void makesound() override {
        cout << name << " hisses softly 🐍" << endl;
    }

    void displayinfo() {
        cout << " name of the snake 🐍" << name << " age " << age << endl;
        if (venomous) {
            cout << "venomous snake here ahghguirthgngnt!!! run!!!" << endl;
        }
    }
};

class monkey : public animal {
public:
    monkey(string n, int a) : animal(n, a) {}
    void makesound() {
        cout << name << " goes Ooh ooh aah aah!" << endl;
    }
    void displayinfo() {
        cout << " name 🐒 " << name << "age " << age << endl;
    }
};

int main() {
    animal a("janwar", 23); //please notice my goofyness ;)
    a.makesound();
    lion l("Poofyhead", 50);
    l.displayinfo();
    l.makesound();
    snake s("Ssssam", 2, 1);
    s.displayinfo();
    s.makesound();
    monkey m("george", 7);
    m.displayinfo();
    m.makesound();

    //trying wrong age input
    try {
        animal bad_animal("dontexist", -5);
    }
    catch (exception& e) {
        cout << "error!!" << e.what() << endl;
    }
}