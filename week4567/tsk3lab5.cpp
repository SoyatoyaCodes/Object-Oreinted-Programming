
// Create a program to simulate basic cache replacement strategies using inheritance: 
// 1. Base Class: Cache 
// a. Attributes: 
// i. 
// capacity (maximum items) 
// ii. 
// currentItems (list of cached items) 
// b. Methods: 
// i. 
// ii. 
// virtual void addItem(int item) (adds item to cache) 
// void printCache() (displays current cached items) 
// 2. Derived Classes (Implement specific replacement strategies): 
// a. FIFOCache: First-In-First-Out 
// i. 
// Evicts the oldest item when cache is full 
// b. LRUCache: Least Recently Used 
// i. 
// Evicts the least recently accessed item when cache is full
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class cache {
protected:
    int capacity;
    vector<string> items;

public:
    cache(int c) : capacity(c) {
    }

    virtual void additem(string thing) {
        items.push_back(thing);
    }

    void printcache() {
        for (auto& it : items) {
            cout << it << " ";
        } cout << endl;
    }
};

class fifocache : public cache {
public:
    fifocache(int c) : cache(c) {}
    //fifo
    void additem(string s) override {
        if (items.size() == capacity) {
            items.erase(items.begin());
        }
        items.push_back(s);
    }
};

// Access = move to end of list. Evict = remove from front.
class lrucache : public cache {
public:

    lrucache(int c) : cache(c) {}

    void additem(string s) override {
        auto it = find(items.begin(), items.end(), s);
        if (it != items.end()) { //it has been found
            items.erase(it);
        }

        else {
            if (items.size() == capacity) {
                items.erase(items.begin());
            }
        }

        items.push_back(s);

    }

};

int main() {
    fifocache fif(2);
    fif.additem("5");
    fif.additem("6");
    fif.printcache();
    fif.additem("67");
    fif.printcache();
    cout << endl;


    lrucache lru(3);
    lru.additem("A");
    lru.additem("B");
    lru.additem("C");
    lru.printcache();  // A B C

    lru.additem("A");  // A is now most recently used
    lru.printcache();  // B C A

    lru.additem("D");  // B is least recently used → evicted
    lru.printcache();  // C A D
}