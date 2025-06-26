// Implement a browser history tracker to simulate webpage navigation using a singly linked list. 
// When users browse the web, browsers track visited pages to allow backward/forward 
// navigation. Your task is to model this using a singly linked list. Implement 
// a BrowserHistory class with the following functionality: 
// 1. Visit a New Page: Add a new URL to the history. 
// 2. Navigate Backward: Move back N steps in the history. 
// 3. Display History: Print the entire history with the current page highlighted. 
// Class Structure 
// 1. Node Class: 
// o Attributes: 
//  url (std::string): The webpage URL. 
//  next (Node*): Pointer to the next node. 
// o Constructor: Initializes url and sets next to nullptr. 
// 2. BrowserHistory Class: 
// o Private Attributes: 
//  head (Node*): Oldest page in history. 
//  tail (Node*): Newest page in history. 
//  current (Node*): Current page for navigation. 
// o Public Methods: 
//  visitPage(std::string url): 
//  Adds a new page to the end of the history. 
//  Updates current to point to the newly added page. 
//  goBack(int steps): 
//  Moves the current pointer backward by steps pages. 
//  If steps exceed available history, stop at the oldest page. 
//  Print the current URL after navigation (e.g., Current URL: 
// https://google.com). 
//  displayHistory(): 
//  Prints all URLs from oldest to newest, marking the current page 
// with [CURRENT]. 
// 3. Destructor: Deallocates all nodes to prevent memory leaks.
#include <iostream>
using namespace std;

struct node {
    string url;
    node* next;

    node(string u) : url(u), next(nullptr) {}
};

class browserhistory {
    node* head;
    node* tail;
    node* current;
public:
    browserhistory() : head(nullptr), tail(nullptr) {}

    void visitnew(string u) {
        node* newnode = new node(u);

        if (tail == nullptr) {
            head = tail = current = newnode;
            return;
        }

        else {
            tail->next = newnode;
            tail = current = newnode;
        }
    }

    //using singly linkedlist...
    //traverse whole thing first to get size and track current pointer position
    //calculate how many steps to take form the start again to simulate going back from currentpos
    //i imagined 6 nodes with current being at 5th pos and going 2 steps back to decide loop logic :)
    void goback(int steps) {
        if (steps < 0) {
            cout << "wrong input made" << endl;
            return;
        }
        node* navigate = head;
        int size = 1;
        int currentpos = 0;
        //using this loop to know the size of my list
        while (navigate->next != nullptr) {
            if (current == head) {
                currentpos = 1;
            }
            navigate = navigate->next;
            size++;
            if (navigate == current) {
                currentpos = size;
                cout << "current pointer points at " << size << " position" << endl;
            }
        }
        //u exit loop with the navigate pointing to the last node plus knowing the size
        //going back if 
        if (size - steps < 0 || currentpos - steps <= 0) {
            cout << "out of bounds error!" << endl;
            cout << "printing oldest history: " << head->url << endl;

            return;
        }
        else {
            int count = 1;
            node* pointy = head;
            while (count != currentpos - steps) {
                pointy = pointy->next;
                count++;
            }
            current = pointy;
            cout << "current points at " << count << " position" << endl;
            cout << "CURRENT URL " << current->url << endl;
            return;
        }
    }

    void displaylinkedlist() {
        if (head == nullptr) {
            cout << "nothing to print, list is empty" << endl;
            return;
        }

        node* printer = head;
        cout << "all browser history: " << endl;
        do {
            if (current == printer) {
                cout << "[CURRENT]-> ";
            }
            cout << printer->url << " -> ";
            printer = printer->next;
        } while (printer != nullptr);
        return;
    }

    ~browserhistory() {
        node* temp = head;
        while (temp != nullptr) {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = current = nullptr;
        cout << "browser history cleared" << endl;
    }

};

int main() {
    browserhistory b;
    b.visitnew("google.com");
    b.visitnew("youtube.com");
    b.visitnew("leetcode");
    b.displaylinkedlist();
    b.goback(1);
}


