// Task 1: 
// C++ provides <chrono> for working with time durations, clocks, and time points. It allows precise measurement and 
// manipulation of time intervals. The steady_clock is one of the clocks offered by <chrono> and is ideal for measuring time 
// intervals because it is not affected by system clock changes. The following example demonstrates the usage of steady_clock to 
// measure the time between two points in your program: 
// #include <iostream> 
// #include <chrono> 
// int main() { 
// auto start = std::chrono::steady_clock::now(); 
// /* Code you want to time */ 
// auto end = std::chrono::steady_clock::now(); 
// std::chrono::duration<double> elapsed_seconds = end - start; 
// std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n"; 
// } 
// In this task, you are required to implement a class Stopwatch that will utilize the std::chrono::steady_clock to accurately 
// measure time. The class should support the following functions: 
//  A start() method that initiates the timing by recording the current time. 
//  A stop() method that stops the timer and calculates the elapsed time since it was started. 
//  A reset() method that resets the stopwatch to its initial state, allowing for a new timing session. 
// Additionally, the class should provide methods to retrieve the elapsed time in different formats: 
//  A method get_elapsed_time_seconds() that returns the time in seconds as a double. 
// A method get_elapsed_time_milliseconds() that returns the time in milliseconds as a double. 
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

class stopwatch {
private:
    chrono::steady_clock::time_point start{};
    chrono::steady_clock::time_point stoptime{};
public:
    //methods
    void startwatch() {
        start = chrono::steady_clock::now(); //initiates time? by recording current?? 
    }

    void stop() {
        stoptime = chrono::steady_clock::now();
    }

    void reset() {
        //reset stop watch to inital state
        start = chrono::steady_clock::time_point{};
        stoptime = chrono::steady_clock::time_point{};
    }

    void get_elapsed_time_seconds() {
        chrono::duration<double> elpstime = stoptime - start;
        cout << "elapsed time in seconds: " << elpstime.count() << endl;
    }

    void get_elapsed_time_milliseconds() {
        // auto duration = chrono::duration_cast< chrono::milliseconds>(stoptime - start);
        chrono::duration<double, milli> elapsedtime = stoptime - start;
        cout << "elapsed time in milliseconds: " << elapsedtime.count() << endl;
    }

};

int main() {
    stopwatch s;
    s.startwatch();
    for (int i = 0; i < 5; i++) {
        cout << "soha is a star" << endl;
    }

    //binary search algo
    int target = 34;
    vector<int> v = { 1,2,34,67 };
    int st = 0;
    int e = v.size() - 1;

    while (st <= e) {
        int mid = (st + e) / 2;
        if (v[mid] == target) {
            cout << "target found! its at postion " << mid << endl;
        }
        if (v[mid] > target) {
            e = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }

    s.stop();
    s.get_elapsed_time_seconds();
    s.get_elapsed_time_milliseconds();
}
