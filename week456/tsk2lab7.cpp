// Implement exception handling in a program where multiple exceptions may be thrown. Use catch(...) to handle 
// unknown exceptions gracefully. 
// Given this code: 
// In the main function use the try-catch block to catch these errors and output what was caught.
#include <iostream>
using namespace std;

void testexception(int x) {
    if (x == 1) throw 10;
    else if (x == 2) throw 2.5;
    else if (x == 3) throw 'A';
    else throw string("unkown error");
}