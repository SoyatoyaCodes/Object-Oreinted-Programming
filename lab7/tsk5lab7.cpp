// you are building a program to check the strength of a password. The program should enforce the following rules: 
// • The password must be at least 8 characters long. 
// • The password must contain at least one digit. 
// • If the password does not meet these requirements, the program should throw an exception. 
// Write a function void checkPassword(const std::string& password) that: 
// • Throws a std::runtime_error if the password is less than 8 characters long. 
// • Throws a std::runtime_error if the password does not contain at least one digit. 
// • Prints "Password is strong and valid." if both conditions are met. 
// In main(), prompt the user to enter a password, call checkPassword, and handle any exceptions. 
// Note: In addition to using the standard std::isdigit function from the <cctype> header, you can check if a 
// character is a digit by comparing its ASCII value directly. This method involves verifying whether the character 
// falls within the ASCII range for numeric digits ('0' to '9'). 

#include <iostream>
#include <exception>
using namespace std;

void checkpassword(const string& pw) {
    if (pw.length() < 8) {
        throw runtime_error("password should be atleast 8 characters long");
    }
    bool num = false;
    for (char it : pw) {
        if (it >= 0 and it <= 9) {
            num = true;
            break;
        }
    }

    if (!num) {
        throw runtime_error("password should include atleast 1 digit");
    }

    if (num) {
        cout << "passowrd is strong and valid" << endl;
        return;
    }
}

int main() {
    try {
        checkpassword("yoyoyo");
    }
    catch (exception& e) {
        cout << "ERROR! " << e.what() << endl;

    }
}



