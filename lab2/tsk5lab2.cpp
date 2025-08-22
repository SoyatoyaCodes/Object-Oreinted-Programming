// Implement a program for a mechanic shop that operates on different cars. The program should include the following 
// features: 
// 1. Car Class: 
// o Each car has a make, model, year, and a dynamically allocated array to store repair costs (to 
// demonstrate deep copy). 
// o Provide a constructor, destructor, copy constructor, and assignment operator to ensure proper 
// memory management. 
// 2. MechanicShop Class: 
// o The mechanic shop maintains a list of cars and performs operations on them. 
// o Use a dynamically allocated array to store the cars (to demonstrate deep copy). 
// 3. Friend Function: 
// o Implement a friend function calculateTotalRepairCost that calculates the total repair cost for a given 
// car. 
// 4. Operator Overloading: 
// o Overload the + operator to combine the repair costs of two cars into a new car (simulating merging 
// repair histories). 
// o Overload the << operator to display car details and repair costs. 
// 5. Deep Copy: 
// o Ensure that all dynamically allocated memory (e.g., repair costs, list of cars) is properly copied using 
// deep copy in the copy constructor and assignment operator.

#include <iostream>
using namespace std;
#include <stdexcept>
#include <string>
#include <cstdlib> //rand() and srand()
#include <ctime> //time()


class car {
private:
    string make;
    string model;
    int year;
    int rcounts;
    double* repaircosts;
public:
    //constructors
    car(string m, string mo, int y, int rc) :make(m), model(mo), year(y), rcounts(rc) {
        //dynamic memory allocation
        repaircosts = new double[rc];
    }

    car() : make(""), model(""), year(0), rcounts(0), repaircosts(nullptr) {

    }

    //deep copy constructor
    car(const car& c2) {
        this->make = c2.make;
        this->model = c2.model;
        this->rcounts = c2.rcounts;
        this->year = c2.year;

        this->repaircosts = new double[rcounts];
        for (int i = 0; i < rcounts; i++) {
            this->repaircosts[i] = c2.repaircosts[i];
        }
    }


    //getters here
    string getmake() const {
        return make;
    }

    string getmodel() const {
        return model;
    }

    int getyear() const {
        return year;
    }

    void getcosts(ostream& os) const {
        os << "repair costs for " << model << " :" << endl;
        for (int i = 0; i < rcounts; i++) {
            os << repaircosts[i] << " ";

        } os << endl;
    }
    int getrcount() {
        return rcounts;
    }

    ~car() {
        delete[] repaircosts;
    }

    //operator overload
    car& operator=(const car& c) {
        if (this == &c) {
            return *this;
        }
        this->rcounts = c.rcounts;
        this->make = c.make;
        this->model = c.model;
        this->year = c.year;

        delete[] this->repaircosts;
        this->repaircosts = new double[rcounts];
        for (int i = 0; i < rcounts; i++) {
            this->repaircosts[i] = c.repaircosts[i];
        }
        return *this;
    }


    car operator+(const car& c) {

        int maxval = max(this->rcounts, c.rcounts);
        int minval = min(this->rcounts, c.rcounts);

        car ca;
        ca.rcounts = maxval;
        ca.repaircosts = new double[maxval];

        for (int j = 0; j < minval; j++) {
            ca.repaircosts[j] = this->repaircosts[j] + c.repaircosts[j];
        }
        for (int i = minval; i < maxval; i++) {
            if (this->rcounts > c.rcounts) {
                ca.repaircosts[i] = this->repaircosts[i];
            }
            else {
                ca.repaircosts[i] = c.repaircosts[i];
            }
        }
        ca.year = 0;
        ca.make = "merged";
        ca.model = "merged";
        return ca;
    }

    void setRepairCost(int index, double value) {
        if (index >= 0 && index < rcounts) {
            repaircosts[index] = value;
        }
        else {
            throw out_of_range("Invalid repair index");
        }
    }

    friend double calculatetotalrepaircost(const car& c);

};

class mechanicshop {
private:
    car* carlist;
    int totcars;
    int currentindex;
public:

    mechanicshop(int tot) : totcars(tot), currentindex(0) {
        carlist = new car[totcars];

    }

    car merge_repairhis(int i, int j) {
        if (i >= 0 && i < totcars && j >= 0 && j < totcars) {
            return carlist[i] + carlist[j];
        }
        else {
            throw invalid_argument("wrong indexes provided");
        }
    }

    void addcar(const car& c) {
        if (currentindex < totcars) {
            carlist[currentindex] = c; // deep copy via overloaded operator=
            currentindex++;
        }
        else {
            throw overflow_error("No more space in the mechanic shop!");
        }
    }

};

double calculatetotalrepaircost(const car& c) {
    double sum = 0;
    for (int i = 0; i < c.rcounts;i++) {
        sum += c.repaircosts[i];
    }
    return sum;
}

ostream& operator<<(ostream& os, const car& c) {
    os << "car :" << c.getmake() << endl;
    os << "model :" << c.getmodel() << endl;
    os << "year: " << c.getyear() << endl;
    c.getcosts(os);
    return os;

}
void setallcosts(car& c) {
    for (int i = 0; i < c.getrcount(); i++) {
        int randomcost = 1000 + rand() % 4001;
        c.setRepairCost(i, randomcost);
    }
}

int main() {
    srand(time(0));//for random cost generation

    car f("ferrari", "488 GTB", 2019, 6);
    car l("lambo", "AvenadorSVJ", 2020, 3);
    car p("porsche", "911 Turbo S", 2021, 2);
    car m("McLaren", "720S", 2019, 8);

    setallcosts(f);
    setallcosts(l);
    setallcosts(p);
    setallcosts(m);


    cout << f << endl;
    cout << "total repair cost for ferrari :" << calculatetotalrepaircost(f) << endl;
    cout << l << endl;
    cout << p << endl;
    cout << m << endl;

    mechanicshop s(4);
    try {
        s.addcar(f);
        s.addcar(l);
        s.addcar(p);
        s.addcar(m);
    }
    catch (exception& msg) {
        cout << "error! " << msg.what() << endl;
    }

    cout << s.merge_repairhis(0, 1);



}

