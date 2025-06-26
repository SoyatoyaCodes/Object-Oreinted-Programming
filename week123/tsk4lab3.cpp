// A doubly linked list is a data structure where each node contains: 
//  Data/Value: The information stored in the node. 
//  Next Pointer: A reference to the next node in the list. 
//  Previous Pointer: A reference to the previous node in the list. 
// This structure allows you to traverse the list in both directions (forward and backward), making 
// some operations more efficient. 
// Implement a simple doubly linked list that supports the following operations: 
//  Traverse Forward and Backward 
//  Forward Traversal: Start at the head (beginning) of the list and move to the tail (end) 
// by following the next pointers, printing or collecting each node's value. 
//  Backward Traversal: Start at the tail of the list and move back to the head by following 
// the previous pointers, printing or collecting each node's value. 
//  Get Value at a Specific Index 
//  Write a function/method that takes an index (with the head at index 0) and returns the 
// value stored at that position in the list. 
//  Consider how you would handle an invalid index (e.g., an index that is out of bounds). 
//  Remove the First Element 
//  Write a function/method that removes the first node (the head) of the list. 
//  Update the pointers accordingly so that the list remains intact (i.e., the new head 
// should have its previous pointer set to null or equivalent). 
//  Add a Value at the End 
//  Write a function/method that appends a new node with a given value at the end (tail) 
// of the list. 
//  Make sure to update the pointers: the current tail’s next pointer should point to the 
// new node, and the new node’s previous pointer should point to the current tail.

//forward and backward traversal with print
//val at index. edge cases. invalid index.
//remove first element
//add val at end
#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* next;
    node* prev;
    //constructor
    node(int val) {
        this->val = val;
        next = prev = nullptr;
    }
};

class doublelink {
private:
    node* head;
    node* tail;
public:
    //constructor
    doublelink() {
        head = tail = nullptr;
    }

    //adding value at the end
    void push_end(int v) {
        node* newnode = new node(v);
        if (head == nullptr && tail == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    //removing first element
    void pop_front() {
        if (head == nullptr && tail == nullptr) {
            cout << "there is nothing to remove from the front" << endl;
            return;
        }

        else {
            node* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
        }
    }

    //traverse forward
    void forward_move() {
        node* current = head;
        while (current != nullptr) {
            cout << current->val << " ->  ";
            current = current->next;
        }
        cout << "null" << endl;
    }
    //traverse backwords
    void backward_move() {
        node* current = tail;
        while (current != nullptr) {
            cout << current->val << " ->  ";
            current = current->prev;
        }
        cout << "null" << endl;
    }

    int val_at_index(int index) {
        if (index < 0) {
            cout << "Invalid index" << endl;
            return -1;
        }
        node* current = head;

        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                cout << "Out of bounds" << endl;
                return -1;
            }
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Invalid index: Out of bounds." << endl;
            return -1;
        } return current->val;
    }
    ~doublelink() {
        node* temp = head;
        while (temp) {
            node* nextnode = temp->next;
            delete temp;
            temp = nextnode;
        }
        cout << "List destroyed.\n";
    }

};

int main() {
    doublelink d1;
    d1.push_end(6);
    d1.push_end(7);
    d1.backward_move();
    d1.forward_move();
    d1.pop_front();
    d1.forward_move();
    cout << "value at index 3: ";
    cout << d1.val_at_index(2) << endl;
    cout << "value at index 0: ";
    cout << d1.val_at_index(0) << endl;
}