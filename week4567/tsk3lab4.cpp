// Stack Implementation 
// A text editor needs to support undo and redo operations efficiently. Implement two stacks using 
// a dynamic array to manage the undo and redo functionality. 
// Operations: 
// • Undo: Pop from the undo stack and push onto the redo stack. 
// • Redo: Pop from the redo stack and push onto the undo stack. 
// • Insert/Delete Text: Push changes onto the 
// undo stack. write the complexity of each operation in 
// comments.
#include <iostream>
#include <string>
using namespace std;

class dynstack {
private:
    string* stack;
    int capacity;
    int top;

    void resize(int newcapacity) { //o(n) time complexity
        string* newstack = new string[newcapacity];
        for (int i = 0; i <= top; i++) {
            newstack[i] = stack[i];
        }

        delete[] stack;
        stack = newstack;
        capacity = newcapacity;
    }

public:
    dynstack(int cap = 3) {
        capacity = cap;
        stack = new string[capacity];
        top = -1;
    }


    dynstack(const dynstack& other) {
        capacity = other.capacity;
        top = other.top;
        stack = new string[capacity];

        for (int i = 0; i <= top; i++) {
            stack[i] = other.stack[i];
        }
    }

    ~dynstack() {
        delete[] stack;
    }

    void push(string value) {
        if (top + 1 == capacity) {
            resize(capacity * 2);
        }
        stack[++top] = value;
    }

    bool isEmpty() { //o(1)
        return top == -1;
    }

    //this is for overwriting to prevent unnecessary memory alloc
    void clear() {
        top = -1;
    }

    string pop() { //o(1)
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return stack[top--];
    }
};

class TextEditor {
private:
    string text;
    dynstack undostack = dynstack(10);
    dynstack redostack = dynstack(10);

public:
    void insertText(string newText) {
        undostack.push(text);
        text += newText;
        redostack.clear();
    }

    void deleteText(int length) {
        if (text.empty()) {
            cout << "Nothing to delete!" << endl;
            return;
        }

        if (length > text.size()) length = text.size();
        undostack.push(text);
        text.erase(text.size() - length, length);
        redostack.clear();
    }

    void undo() {
        if (!undostack.isEmpty()) {
            redostack.push(text);
            text = undostack.pop();
        }
        else {
            cout << "Nothing to undo" << endl;
        }
    }

    void redo() {
        if (!redostack.isEmpty()) {
            undostack.push(text);
            text = redostack.pop();
        }
        else {
            cout << "Nothing to redo" << endl;
        }
    }

    void displayText() {
        cout << "Text: " << text << endl;
    }
};

int main() {
    TextEditor edit_it;

    edit_it.insertText("I guess I am cool !(0o0)!");
    edit_it.displayText();

    edit_it.insertText("... maybe not (~_~!)");
    edit_it.displayText();

    edit_it.undo();
    edit_it.displayText();
    edit_it.redo();
    edit_it.displayText();
    edit_it.deleteText(8);
    edit_it.displayText();
    edit_it.undo();
    edit_it.displayText();
    edit_it.deleteText(4);
    edit_it.displayText();
}
