// In a library, books need to be tracked with details such as title, author,
// and availability. Members of the library can borrow and return books, but
// they are limited to borrowing a maximum of three books at a time. The system
// should ensure that only available books can be borrowed and provide a
// structured way to track which books a member has taken. When a book is
// returned, it becomes available for other members. A librarian is responsible
// for managing the books by adding and removing them. When a member requests a
// book, the system checks if it is available. If available, the book is marked
// as borrowed, and it is added to the member's borrowing list. If a member
// wants to return a book, the system ensures that the book is returned in the
// same order it was borrowed, following a First-In-First-Out (FIFO) policy. If
// a book is not available, the system displays a message indicating that it is
// currently borrowed by another member. The client program (main.cpp) acts as
// the interface through which users interact with the system. It initializes
// the library with some books and members. Librarians can then add or remove
// books as needed, and members can borrow or return books. The system provides
// a display function to show the current status of all books, indicating
// whether they are available or borrowed.

#include <algorithm>
#include <cctype> // for tolower
#include <iostream>
#include <stdexcept>
#include <unordered_map> //for tracking which member took which book
using namespace std;
#include <vector>

// library
// librarians: have access to add new books or remove them
// members

struct book {
    string title;
    string author;
    bool available; // we can use this to create the display function for
    // availablity to check status of books

    void bookinput() {
        cout << "enter title of the book: " << endl;
        getline(cin >> ws, title);
        cout << "enter the name of author: " << endl;
        getline(cin, author);

        while (true) {

            cout << "confirm add? type 1 or zero for NO" << endl;
            cin >> available;

            if (available == 1 || available == 0) {
                break;
            }

            try {
                throw "wrong input made!";
            }
            catch (const char* e) {
                cout << "please choose 1(YES) or 0(NO) " << e << endl;
            }
        }
    }

    // default constructor for input
    book() { bookinput(); }
};

struct member {
    string name;
    inline const static int book_capacity = 3;
    vector<book> borrowed;
};

struct librarian {
    string name;
    int id;
};

class library {
public:
    vector<book> collection;
    vector<librarian> staff;
    vector<member> membership;

    library() {}

    void register_member(member& m) { membership.push_back(m); }

    void let_borrow(member& m) {
        if (m.borrowed.size() == m.book_capacity) {
            cout << "you cannot borrow any more books than 3, return one of them to "
                "borrow a new one"
                << endl;
            book_returned(m);
            return; // because what if user types in wrong title in the function, we
            // still are giving it chance to add another book in rest code
        }
        if (m.borrowed.size() < m.book_capacity) {
            string name;
            cout << "what book you want to borrow??" << endl;
            getline(cin >> ws, name);
            bool found = false;

            for (auto it = collection.begin(); it != collection.end(); ++it) {

                if (tolowerfunc(it->title) == tolowerfunc(name) && it->available) {
                    cout << "yesss we have this book available!!" << endl;
                    m.borrowed.push_back(*it);
                    found = true;
                    it->available = false;
                    cout << "enjoy your book!" << endl;
                    break; // ADD THE QUEUE REQUIREMENT HERE! later on ohhh wait dont
                    // erase but instead do available = false;
                }
            }

            if (!found) {
                cout << "book not available, you can not borrow it" << endl;
            }
        }
    }

    string tolowerfunc(string& val) {
        string n = "";
        for (int i = 0; i < val.size(); i++) {
            n += tolower(val[i]);
        }
        return n;
    }

    void book_returned(member& m) {
        bool found = false;
        if (m.borrowed.empty()) {
            cout << "you have not borrowed any books yet" << endl;
            return;
        }
        // i can ask user if they want to add here and then call lend book function

        string bookname;
        while (true) {
            cout << "which book you want to return?" << endl;
            getline(cin, bookname);

            if (!m.borrowed.empty()) {
                for (auto it = m.borrowed.begin(); it != m.borrowed.end();) {
                    if (tolowerfunc(it->title) ==
                        tolowerfunc(bookname)) { // ADD THE FIFO REQUIREMENT HERE
                        cout << "thank you for returning the book!";
                        collection.push_back(
                            *it); // have to derefernce it! adding book back to library
                        m.borrowed.erase(it);
                        found = true;
                        break;
                    }
                    else {
                        ++it;
                    }
                }
            }
            if (!found) {
                cout << "you either entered the wrong title or book not borrowed"
                    << endl;
                return;
            }
            return;
        }
    }

    void displaycollection() {
        if (collection.empty()) {
            cout << "no books exist in library" << endl;
            return;
        }
        cout << " ˖⁺‧₊˚♡˚₊‧⁺˖ book collections ˖⁺‧₊˚♡˚₊‧⁺˖" << endl;
        int numbering = 0;
        for (auto& it : collection) {
            cout << numbering++ << ") " << it.title << " by " << it.author << " "
                << " status: " << it.available << endl;
        }
    }

    void displaydata() {
        if (membership.empty()) {
            cout << "no members exist in library" << endl;
            return;
        }
        cout << " ˖⁺‧₊˚♡˚₊‧⁺˖ book borrow history ˖⁺‧₊˚♡˚₊‧⁺˖" << endl;
        for (auto& it : membership) {
            cout << it.name << " :" << endl;
            cout << "books borrowed: " << endl;
            if (it.borrowed.empty()) {
                cout << "none";
            }
            else {
                for (auto& b : it.borrowed) {
                    cout << b.title << " by " << b.author << endl;
                }
                cout << endl;
            }
        }
    }

    void remove_book() {
        bool found = false;
        string name;
        getline(cin >> ws, name);
        for (auto it = collection.begin(); it != collection.end();) {
            if (tolowerfunc(it->title) == tolowerfunc(name)) {
                if (it->available) {
                    cout << "removing the book from collection..." << endl;
                    collection.erase(it);
                    cout << "removed!" << endl;
                    found = true;
                    break;
                }

                if (it->available != 1) {
                    cout << "this book is currenly borrowed and can not be removed"
                        << endl;
                }

                return;
            }
            else {
                ++it;
            }
        }
        if (!found) {
            cout << "book can not be removed" << endl;
            return;
        }
    }

    void delete_membership(member& m) {
        for (auto it = membership.begin(); it != membership.end();) {
            if (it->name == m.name) {
                membership.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void addnewbooks() {
        int count;
        cout << "how many books you want to add?" << endl;
        cin >> count;
        for (int i = 0; i < count; i++) {
            book b;
            if (b.available) {
                collection.push_back(b);
            }
        }
    }
};

int main() {

    library iba_lib; // this does a lot of work

    member m1;
    m1.name = "soha";
    member m2;
    m2.name = "ali";

    iba_lib.register_member(m1);
    iba_lib.register_member(m2);

    iba_lib.staff.push_back({ "samantha", 01 });
    iba_lib.staff.push_back({ "grace", 02 });
    iba_lib.staff.push_back({ "lucy", 03 });

    bool libisopen = true;
    while (libisopen) {

        string name;
        cout << "confirm you are a librarian. Enter your name: " << endl;
        cin >> name;

        bool found = false;
        for (const auto& it : iba_lib.staff) {
            if (it.name == name) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "you can make changes to the book collection!" << endl;
            cout << "what task you want to perform? " << endl;
            int choice;
            cout << "1)add new book?             2)register new member? " << endl;
            cout << "3)put returned book back?   4)lend a book?" << endl;
            cin >> choice;

            switch (choice) {
            case 1: {
                iba_lib.addnewbooks();
                iba_lib.displaycollection();
                break;
            }

            case 2: {
                member m;
                cout << "enter your name to register" << endl;
                cin >> m.name;
                iba_lib.register_member(m);
                break;
            }

            case 3: {
                bool ismember = false;
                if (iba_lib.membership.empty()) {
                    cout << "no members have registered to library!" << endl;
                    break;
                }
                else {
                    string name;
                    cout << "hello customer!! welcome! to return your book, please type "
                        "your name?  "
                        << endl;
                    cin >> name;
                    for (auto it = iba_lib.membership.begin();
                        it != iba_lib.membership.end(); it++) {
                        if (iba_lib.tolowerfunc(it->name) == iba_lib.tolowerfunc(name)) {
                            iba_lib.book_returned(*it);
                            ismember = true;
                        }
                    }
                }

                if (!ismember) {
                    cout << "You don't seem to be a library member! Would you like to "
                        "register now? (y/n): ";
                    char choice;
                    cin >> choice;
                    if (tolower(choice) == 'y') {
                        member m;
                        m.name = name;
                        iba_lib.register_member(m); // simulate "case 2"
                    }
                }
                break;
            }

            case 4: {
                string name;
                cout << "enter your name please" << endl;
                cin >> name;
                for (auto& it : iba_lib.membership) {
                    if (it.name == name) {
                        iba_lib.let_borrow(it);
                    }
                }
                break;
            }

            default: {
                cout << "invalid choice made" << endl;
            }
            }
        }
        else {
            cout << "access denied, not a registered librarian" << endl;
        }
        char c;
        cout << "do you want to perform actions? (y/n)" << endl;
        cin >> c;

        if (tolower(c) != 'y') {
            libisopen = false;
        }
    }

    iba_lib.displaydata();
    return 0;
}

// NOTES

// fix errors in returnbook function. it doenst take any user input

// VEC.ERASE() DOES NOT WORK ON RANGE BASED FOR LOOP, THE FUNCTION NEEDS AN
// ITERATOR. NOT A REFERENCE
//  void delete_membership(member& m) {
//      for (member& it : membership) {
//          if (it.name == m.name) {   //it is *ptr under hood
//              membership.erase(it);
//          }
//      }
//  }

// void delete_membership(member& m){//ERROR! UPDATE IT WHEN NOT ERASING ONLY!
// BECASUE AFTER ERASE IT BECOMES UNDEFINED
//  .erase returns a new iterator, you cant increment the old one
// for(auto it= membership.begin(); it!= membership.end();it++){
//         if(it->name == m.name){
//             membership.erase(it); //here it is an iterator
//         }
//    }
// }
