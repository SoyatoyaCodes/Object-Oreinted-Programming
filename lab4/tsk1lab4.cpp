// Queue Implementation 
// A printer processes print jobs in a first-in, first-out (FIFO) order. Implement a queue using a 
// dynamic array to handle the print queue efficiently. 
// Operations: 
// • Add a new print job: Enqueue operation. 
// • Process a print job: Dequeue operation. 
// • Resize the queue when full: Ensure dynamic resizing maintains efficiency. 
// Analyze the complexity of enqueue and dequeue operations.

#include <iostream>
using namespace std;
#include <ctime> //time
#include <cstdlib> //srand and rand

template<typename T>//using templates to handle most type of data
class diy_queue {
private:
    T* myqueue;
    int capacity;
    int size;

public:
    //constructor
    diy_queue(int c) : capacity(c), size(0) {
        myqueue = new T[c](); //i guess it will initialize an array?
    }

    //why cant i do new T[capacity](0); why doesnt new accept intialization like this?

    void resize() {
        //a new array 
        T* newq = new T[2 * capacity];
        //paste our data into it
        for (int i = 0; i < this->size; i++) {
            newq[i] = this->myqueue[i];
        }
        delete[] this->myqueue;
        this->myqueue = newq;
        this->capacity = 2 * capacity;
        return;
    }

    void enqueue(T data) {
        if (size == capacity) {
            resize(); //O(N)
        }
        myqueue[size] = data; // O(1) TIME COMPLEXITY 
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "nothing to delete here" << endl;
            return;
        }

        T* newq = new T[capacity];
        for (int i = 1; i < size; i++) {
            newq[i] = this->myqueue[i]; //o(n) inefficient
        } size--;

        delete[] this->myqueue; //this one deletes the whole thing so yea
        this->myqueue = newq;
    }

    ~diy_queue() {
        delete[] myqueue;
    }
};

int main() {
    srand(time(0));
    diy_queue <int>q(5);
    for (int i = 0; i < 5; i++) {
        q.enqueue(rand() % 10 + 1);
    }
}

//add front and rear ptrs to make dequeue O(1)