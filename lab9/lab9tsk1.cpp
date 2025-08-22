// Task 1: 
// You are provided with a list of elements containing information about their name, symbol, and atomic number. 
// Utilize functors and STL algorithms to achieve the following:  
// • Sort: Create a custom functor to sort the elements based on two criteria:  
// o Primary: Atomic number (ascending order)  
// o Secondary: Element name (alphabetical order)  
// • Count: After sorting, determine the number of elements with names longer than 5 characters using a 
// custom filter functor.  
// • Transform: Create a new list containing the element symbols transformed to uppercase using a lambda 
// function.  
// Task Instructions:  
// 1. Complete the main function by initializing the elements vector with your desired element data (name, 
// symbol, atomic number).  
// 2. Implement the logic to process the sorted elements, long name count, and uppercase symbols as needed. 
// 3. Modify the code to allow users to specify a custom minimum atomic number for filtering elements 
// during sorting 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

struct Element {
    string name;
    string symbol;
    int atomicNumber;
};

struct SortElements {
    bool operator()(const Element& a, const Element& b) const {
        if (a.atomicNumber == b.atomicNumber) {
            return a.name < b.name;
        }
        return a.atomicNumber < b.atomicNumber;
    }
};

struct LongNameFilter {
    bool operator()(const Element& e) const {
        return e.name.size() > 5;
    }
};

int main() {
    vector<Element> elements = {
        {"Hydrogen", "H", 1},
        {"Helium", "He", 2},
        {"Lithium", "Li", 3},
        {"Beryllium", "Be", 4},
        {"Boron", "B", 5},
        {"Carbon", "C", 6},
        {"Nitrogen", "N", 7},
        {"Oxygen", "O", 8},
        {"Fluorine", "F", 9},
        {"Neon", "Ne", 10}
    };

    int minAtomic;
    cout << "Enter minimum atomic number for filtering: ";
    cin >> minAtomic;

    vector<Element> filtered;
    copy_if(elements.begin(), elements.end(), back_inserter(filtered),
        [minAtomic](const Element& e) { return e.atomicNumber >= minAtomic; });

    sort(filtered.begin(), filtered.end(), SortElements());

    int longNameCount = count_if(filtered.begin(), filtered.end(), LongNameFilter());

    vector<string> uppercaseSymbols;
    transform(filtered.begin(), filtered.end(), back_inserter(uppercaseSymbols),
        [](const Element& e) {
            string sym = e.symbol;
            for (char& c : sym) c = toupper(c);
            return sym;
        });

    cout << "\nSorted and Filtered Elements:\n";
    for (auto& e : filtered) {
        cout << e.atomicNumber << " " << e.name << " (" << e.symbol << ")\n";
    }

    cout << "\nNumber of elements with long names (>5 chars): " << longNameCount << "\n";

    cout << "\nUppercase Symbols:\n";
    for (auto& s : uppercaseSymbols) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}
