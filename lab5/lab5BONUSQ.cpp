#include <iostream>
#include <vector>
//#include <tuple>
using namespace std;
//deterministic finite automation: used to spot patterns in strings
//tuple<int, string> name(3,"bro");

// State (Class) 
//  Private: 
// o bool isFinal: A flag to check if the state is final. 
// o State* t0: Transition on input 0. 
// o State* t1: Transition on input 1. 
//  Public Methods: 
// o State(): Constructor, initializes state as non-final with no transitions. 
// o void setFinal(): Marks the state as a final state. 
// o void setTransition0(State* s): Sets the transition for input 0. 
// o void setTransition1(State* s): Sets the transition for input 1. 
// o State* getTransition0(): Returns the state transitioned to on input 0. 
// o State* getTransition1(): Returns the state transitioned to on input 1. 
// o bool isFinalState(): Returns true if the state is final, otherwise false. 

//DFA (Class) 
//  Private: 
// o std::vector<State*> Q: Set of states in the DFA. 
// o State* q0: Pointer to the start state. 
//  Public Methods: 
// o DFA(int n = 0): Constructor, initializes a DFA with n states. 
// o ~DFA(): Destructor, cleans up allocated memory. 
// o void addState(): Adds a new state to the DFA. 
// o void addTransition(int from, char c, int to): Adds a transition from state from to state to on character c. 
// o void setFinalState(int i): Marks state i as a final state. 
// o void setStart(int i): Sets state i as the start state. 
// o bool isComplete(): Returns true if all states have transitions and a start state is set. 
// o bool accepts(const std::string& s) const: Returns true if the DFA accepts the input string s. 

class state {
private:
    bool isfinal;
    state* t0; //transition is basically moving nodes
    state* t1;
public:
    state() : isfinal(0), t0(nullptr), t1(nullptr) {}

    void setfinal() {
        isfinal = true;
    }
    //set which obj you transition to for input 0
    void settransition0(state* s) {
        t0 = s;
    }
    void settransition1(state* s) {
        t1 = s;
    }

    state* gettransition0() {
        return t0;
    }

    state* gettransition1() {
        return t1;
    }

    bool isfinalstate() {
        return isfinal == true;
    }
};


class dfa {
public:
    vector<state*> Q;
    state* q0;  //initial state

    dfa(int n = 0) : q0(nullptr) {
        Q.resize(n);
    }

    void addstate() {
        state* newstate = new state();
        Q.push_back(newstate);
    }

    void setstart(int i) {
        q0 = Q[i];
    }
    //it helps u make the state pointing structure
    void addtransition(int from, char c, int to) {
        if (c == '0') {
            Q[from]->settransition0(Q[to]);
        }
        if (c == '1') {
            Q[from]->settransition1(Q[to]);
        }
    }

    void setfinalstate(int i) {
        Q[i]->setfinal();
    }

    //Returns true if all states have transitions and a start state is set.  
    bool iscomplete() {
        int count = 0;
        for (state* s : Q) {
            if (s->gettransition0() != nullptr && s->gettransition1() != nullptr) {
                count++;
            }
        }  if (count == Q.size() && q0 != nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    bool accepts(string& s) {
        state* current = q0;
        for (char c : s) {
            if (c == '0') {
                current = current->gettransition0();
            }
            else if (c == '1') {
                current = current->gettransition1();
            }
            else {
                cout << "wrong input made";
                return false;
            }
        }
        if (current->isfinalstate()) {
            return true;
        }
        else {
            return false;
        }
    }

    ~dfa() {
        for (state* it : Q) {
            delete it;
        }
    }

};

int main() {
    dfa d;
    d.addstate();
    d.addstate();
    d.addstate();
    d.setstart(0); //0th index 
    d.Q[0]->settransition1(d.Q[0]);
    d.Q[0]->settransition0(d.Q[1]);
    d.Q[1]->settransition0(d.Q[2]);
    d.Q[1]->settransition1(d.Q[0]);
    d.Q[2]->settransition0(d.Q[2]);
    d.Q[2]->settransition1(d.Q[2]);
    d.setfinalstate(2);
    if (d.iscomplete()) {
        //strings
        string s1 = "10101010101"; //0 or false
        string s2 = "100001101010101011"; //1 or true
        cout << d.accepts(s1) << endl;
        cout << d.accepts(s2) << endl;
    }

    else {
        cout << "complete the diagram first";
    }

    //basically, the dfa i have implemented detects if the string contains consecutive zeros. if not then it returns false
}