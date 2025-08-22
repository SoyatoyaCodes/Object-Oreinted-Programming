// Implement a StringProcessor class in C++ with three overloaded process methods to 
// manipulate strings in different ways: 
// 1. std::string process(const std::string& input) 
// Reverses the input string. 
// Example: process("hello") → "olleh". 
// 2. std::string process(const std::string& str1, const std::string& str2) 
// Concatenates the two strings with a space. 
// Example: process("Hello", "World") → "Hello World". 
// 3. std::string process(const std::string& input, int repeat) 
// Repeats the input string repeat times. 
// Example: process("ha", 3) → "hahaha"

#include <iostream>
using namespace std;
#include <string>

class stringprocessor {
public:
    string process(const string& input) {
        //reversing string manually
        string out = "";
        for (int i = input.length() - 1; i >= 0; i--) {
            out += input[i];
        } return out;
    }

    string process(const string& s1, const string& s2) {
        return s1 + " " + s2;
    }

    string process(const string& input, int repeat) {
        string rep = "";
        for (int i = 0; i < repeat; i++) {
            rep += input;
        } return rep;
    }
};

int main() {
    stringprocessor p;
    string s;
    string s2;
    cout << "input string 1:";
    getline(cin >> ws, s);
    cout << "input string 2";
    getline(cin >> ws, s2);
    cout << p.process(s) << endl;
    cout << p.process(s, 3) << endl;
    cout << p.process(s, s2) << endl;
}