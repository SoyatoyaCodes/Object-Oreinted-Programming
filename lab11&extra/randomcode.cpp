// Write a recursive method writeChars() that accepts an integer parameter n and that prints out n
// characters as follows. The middle character of the output should always be an asterisk ("*"). If you are
// asked to write out an even number of characters, then there will be two asterisks in the middle ("**").
// Before the asterisk(s) you should write out less-than characters (’<’). After the asterisk(s) you should
// write out greater-than characters (’>’). See the following for some example calls along with the output.

#include <iostream>
using namespace std;

void writechars(int n) {
    if (n <= 0) return;
    if (n == 1) cout << "*";
    if (n == 2) cout << "**";
    if (n > 2) {
        cout << "<";
        writechars(n - 2);
        cout << ">";
    }
    else return;
}

int main() {
    writechars(3);
}
//  wrong logic: 
//  void writechars(int n){
//     static int inputval =n;
//  if(n = inputval/2) {  if(n%2 ==0) //even 
//     {
//         cout<<"**";
//     }
//      else {cout<<"*";}//odd
// }

// else{
//     cout<<"<";
//     writechars(n-1);
//     cout<<">";
// }

// }

// Think of it like layers of an onion:

// You peel off < and > from the outside (recursive calls), thats what n-2 is for.

// Until you hit the core (* or **),

// Then you rebuild the onion back outward (backtracking).
