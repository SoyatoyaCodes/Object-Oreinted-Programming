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


int main() {
    try {
        testexception(1);
        testexception(34);
        testexception(2);
        testexception(3);
    }

    catch (int& msg) {
        cout << "error caught: " << msg << endl;
    }
    catch (char*& msg) {
        cout << "oopsie! " << msg << endl;
    }

    catch (double& msg) {
        cout << "woah mistakes happen!" << msg << endl;
    }


    //block to catch unkown error
    catch (...) {

    }
}

//when one error occurs, the try block wont excute rest of the code written in it and terminates