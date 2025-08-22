// This lab task focuses on checking if an expression contains balanced opening and closing braces ({ and }). Utilize a 
// custom functor and STL algorithms to achieve this. Create a custom functor named BalancedBraces that 
// takes a string expression as input and returns true if the expression contains balanced opening and closing braces 
// ({ and }), and false otherwise.  
// Task Instructions:  
// 1. Implement the operator() function within the BalancedBraces functor.  
// 2. Inside the operator function, iterate through the characters of the expression string.  
// 3. Maintain a counter for opening and closing braces.  
// 4. Increment the opening brace counter for each encountered '{' and decrement the closing brace counter 
// for each encountered '}'.  
// 5. If a closing brace is encountered but the opening brace counter is zero, the expression is unbalanced.  
// 6. Return true if the expression ends with balanced counters (both zero) and false otherwise

#include <iostream>
#include <string>
using namespace std;

struct BalancedBraces {
    bool operator()(const string& expr) const {
        int openCount = 0;
        for (char c : expr) {
            if (c == '{') openCount++;
            else if (c == '}') {
                if (openCount == 0) return false;
                openCount--;
            }
        }
        return openCount == 0;
    }
};

int main() {
    BalancedBraces checker;
    string expr;
    cout << "Enter an expression with braces: ";
    getline(cin, expr);
    if (checker(expr)) {
        cout << "The expression has balanced braces.\n";
    }
    else {
        cout << "The expression is NOT balanced.\n";
    }
    return 0;
}
