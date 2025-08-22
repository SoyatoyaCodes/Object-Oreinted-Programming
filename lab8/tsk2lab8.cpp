// A student learning about data structures wants to implement a linked list that is not limited to a single data type. 
// Create a template class GenericLinkedList that includes:  
//  Methods for inserting and deleting elements at the end of tail of the list.   
//  Exception handling for attempts to delete from an empty list  
//  A method to display all elements in the list. 
// Test cases that demonstrate the list’s functionality with different data types
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class GenericLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    GenericLinkedList() : head(nullptr) {}

    void insertAtTail(T val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteFromTail() {
        if (!head) {
            throw runtime_error("Cannot delete from an empty list.");
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~GenericLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Test cases
int main() {
    GenericLinkedList<int> intList;
    intList.insertAtTail(10);
    intList.insertAtTail(20);
    intList.insertAtTail(30);
    intList.display();
    intList.deleteFromTail();
    intList.display();

    GenericLinkedList<string> stringList;
    stringList.insertAtTail("Hello");
    stringList.insertAtTail("World");
    stringList.display();

    GenericLinkedList<float> floatList;
    floatList.insertAtTail(1.1f);
    floatList.insertAtTail(2.2f);
    floatList.insertAtTail(3.3f);
    floatList.display();
    floatList.deleteFromTail();
    floatList.display();

    // Exception test
    GenericLinkedList<int> emptyList;
    try {
        emptyList.deleteFromTail();
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
