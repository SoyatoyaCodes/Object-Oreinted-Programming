// Create a class to track your pocket money. It should have attributes like source, amount received etc.  
// Keep track of the total amount in your wallet by using a static variable. It should increase each time a new object is created 
// (more money is received).  
// Display the updated money each time in the format given below. 

#include <iostream>
#include <unordered_map>
#include <cctype> //tolower
#include <algorithm>
using namespace std;

//aditional feature
class money_2_pkr {
protected:
    unordered_map<string, double> rates{
        {"pkr", 1.0 },{"dollars", 278.0},
        {"euros", 300.0},
        {"pounds", 350.0}
    };
public:

    string converttolower(string type) {
        transform(type.begin(), type.end(), type.begin(), [](unsigned char c) {
            return tolower(c);
            });
        return type;

    }

    double converttopkr(double amount, const string& t) {
        // ::tolower(type);//wrong! tolower works on characters and not strings
        double pkramount;
        string lowered = converttolower(t);//this is r type right? parmeter and not l type

        if (rates.find(lowered) != rates.end()) {
            pkramount = amount * rates[lowered];
        }

        else {
            cout << "currency not recognized, assuming " << amount << " is in pkr " << endl;
            pkramount = amount;
        }
        return pkramount;
    }

};

class trackmoney : public money_2_pkr {
private:
    string source;
    double amount_recieved;
    string type;//euros, dollars, pounds or pkr
    inline static double tracker = 0;
public:
    //if type is other than these currencie
    trackmoney(string s, double r, string t) : source(s), amount_recieved(r), type(t) {
        tracker += converttopkr(r, t);
        displaymoney();
    }

    void displaymoney() {
        cout << "amount recieved: " << amount_recieved << "    " << "total in pkr: " << tracker << endl;
    }
};

int main() {
    trackmoney first_deposit("daddy", 45, "euros");
    trackmoney second_deposit("stolenmoney", 234, "dollars");
    trackmoney third_deposit("eidi", 2, "rupees");

}