// Implement the Animal class and Pet interface as shown in the UML diagram  
// Create the derived classes (Spider, Cat, and Fish) with their proper inheritance relationships  
// Implement collections (using vectors or lists) that store Animals and Pets separately  
// Test which methods can be called on objects from each collection 
// Submission Guidelines: 
// Include any challenges you faced and how you overcame them. 
// Evaluation Criteria: 
// 1. Proper implementation of all the required classes and their relationships. 
// 2. Correct use of inheritance, polymorphism, and abstract class. 
// 3. Code readability and proper comments. 
// 4. Creativity in solving the problems 

#include <iostream>
#include <vector>
#include <string>
#include <random> //trying new lib here!
#include <cstdlib> //rand and srand
#include <ctime> //time
using namespace std;
//interfaces ie abstract classes. bascially, we use these interfaces to interact with the inherited classes
class animal {
protected:
    int legs;
public:
    animal(int l) : legs(l) {}
    virtual void walk() = 0;
    virtual void eat() = 0;
    virtual ~animal() {};
};

//pet interface

class pet {
protected:
    string name;
public:

    pet(string n) : name(n) {}

    string getname() {
        return name;
    }

    void setname(string n) {
        name = n;
    }

    virtual void play() = 0;
    virtual ~pet() {};
};


class spider : public animal {
public:
    spider(int l) : animal(l) {}
    void walk() {
        cout << "it crawls" << endl;
        cout << R"(
      / _ \
    \_\(_)/_/
     _//"\\_ 
      /   \
    )" << endl;
    }
    void eat() {
        string dummy;
        cout << "Worms! they eat worms or their own mini spider fam. i know!! eww" << endl;
        cout << "press enter to feed this worm to the spider!" << endl;
        cout << R"(
               oo
               |"
               |
             --'
    )" << endl;
        getline(cin, dummy);
        cout << "damn! it died nooo XoX_-_-__---.." << endl;
    }
};

class cat : public animal, public pet {
public:
    cat(int l, string n) : animal(l), pet(n) {}

    void walk() {
        cout << "she walks so beautifully! meowww";
        cout << R"(
      ≽^•⩊•^≼ฅ
    )" << endl;
    }

    void eat() {
        cout << "do you wanna feed the cat? y/n" << endl;
        bool input;
        cin >> input;
        if (input) {
            cout << "yum yum yummy!⎝ ≽ > ⩊ < ≼ ⎠";
        }
        else {
            cout << "cat shrinked cause of hunger womp womp... " << endl;
            cout << " ₍^. ̫.^₎" << endl;
        }
    }

    void play() {
        string dummy;
        vector<string> cattoys{
        "🧶",  // Yarn
        "🪀",  // Yo-yo (toy)
        "🧸",  // Teddy
        "🐭",  // Mouse
        "🪁",  // Kite
        "🎾",  // Ball
        "🦋",  // Butterfly
        "🎀",  // Ribbon
        "🌈",  // Rainbow
        "🪷"   // Lotus 
        };
        random_device rd;
        mt19937 gen(rd());
        //range wrapper
        uniform_int_distribution<> dist(0, cattoys.size() - 1);

        cout << "cat loves some cool toys!!" << endl;
        cout << "click enter to generate a random colour toy!!" << endl;
        getline(cin, dummy);

        cout << "Your cat found a random toy: " << cattoys[dist(gen)] << " 😺\n";
        cout << "cat is happy ฅ^•ﻌ•^ฅ" << endl;
    }
};

class fish : public animal, public pet {
public:
    fish(string n, int l) : animal(l), pet(n) {}

    void walk() {
        cout << "i swim weeeheee" << endl;
        cout << R"(
               O  o
          _\_   o
>('>   \\/  o\ .
       //\___=
          ''
    )" << endl;
    }

    void eat() {
        cout << "seaweed yummy!" << endl;
        cout << R"( °:•.🐠*.•🪸.•:°)" << endl;
    }

    void play() {
        srand(time(0)); //for seeding
        // string array[5]{"hi"};//this will initalize only the first element with hi. c style arrays dont default to filling all vacant positons with the passed val
        vector<bool>vec(5, 0);
        int random_index = rand() % 5;
        vec[random_index] = 1;

        cout << R"(
    ✪  ✪  ✪  ✪  ✪
    0   1  2   3  4
    )" << endl;

        cout << "Behind which of these objects is the fish hiding? Enter a number: ";

        int num;

        while (true) {
            cin >> num;

            if (num >= 0 && num < 5) {
                break;
            }

            else {
                cout << "wrong input made. RENTER CORRECT INDEX!" << endl;
            }

        }

        if (vec[num] == 1) {
            cout << "yay you found the fish!" << endl;
            cout << R"(
        ,-,
      ,/.(     __
   ,-'    `!._/ /
  > @ )<|    _ <
   `-....,,;' \_\
        
        )" << endl;
        }

        else {
            cout << "so sad :( try again NEVER.... YOU ONLY GET ONE TRY!" << endl;
        }
    }

};

// g++ filename.cpp -o filename -Wl,--subsystem,console

int main() {
    //creating vectors to store animals and pets seperately  
    vector<animal*>animals;
    vector<pet*> pets;
    //spider, fish, cat,
    animals.push_back(new spider(8));
    animals.push_back(new cat(4, "cutie"));
    pets.push_back(new cat(4, "stampy"));
    pets.push_back(new fish("dory", 0));

    for (auto* it : animals) {
        it->eat();
        it->walk();
        // it->play();//but cat also can be stored in animal cant it? so how to access play func?
        if (pet* p = dynamic_cast<pet*>(it)) {
            p->play();
        }
    }

    for (auto* it : pets) {
        cout << "hi my name is " << it->getname();
        it->play();
        if (animal* a = dynamic_cast<animal*>(it)) {
            a->eat();
            a->walk();
        }
    }
    //destructors
    for (auto* a : animals) delete a;
    for (auto* p : pets) delete p;

}
