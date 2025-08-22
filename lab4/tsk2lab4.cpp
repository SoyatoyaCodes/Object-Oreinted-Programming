// Dynamic Array 
// An online gaming platform maintains a dynamic leaderboard that expands as new players join. 
// Implement a dynamic array to store player scores and efficiently resize the leaderboard as 
// needed. 
// Requirements: 
// • Implement a dynamically resizing array. 
// • Support efficient score updates. 
// • Ensure optimal resizing strategy.

#include <iostream>
using namespace std;
class leaderboard {
private:
    int* scores;
    int size;
    int capacity;
public:
    leaderboard(int c) : size(0), capacity(c) {
        scores = new int[c];
    }

    void resize(int capacity) {
        int* newarr = new int[2 * capacity];
        for (int i = 0; i < size; i++) {
            newarr[i] = scores[i];
        }
        delete[] scores;
        scores = newarr;
        this->capacity = 2 * capacity;
    }

    void addnewscore(int data) {
        if (size == capacity) {
            cout << "resizing array..." << endl;
            resize(capacity);
        }

        scores[size] = data;
        size++;

    }

    void updatescore(int newscore, int index) {
        if (index < 0 || index >= size) { cout << "wrong index provided!"; return; }
        else {
            scores[index] += newscore;
            cout << "score has been successfully updated!" << endl;
        }
    }


    void displayboard() {
        cout << "all the leaderboard scores: " << endl;
        for (int i = 0; i < size; i++) {
            cout << scores[i] << " ";
        }
    }

    ~leaderboard() {
        delete[] scores;
    }

};

int main() {
    leaderboard f(3);
    f.addnewscore(56);
    f.addnewscore(86);
    f.addnewscore(6);
    f.addnewscore(76);
    f.updatescore(2, 2);
}