#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>

#include <thread>        
#include <mutex>         
#include <condition_variable>

using namespace std;

class FizzBuzz {
private:
    int n;

    std::mutex mtx;
    std::condition_variable cv;

    int counter;

public:
    FizzBuzz(int n) {
        this->n = n;
        counter = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (; counter <= n; ) {
            std::unique_lock<std::mutex> lck(mtx);
            if (counter % 3 == 0 && counter % 5 != 0) {
                printFizz();
                counter++;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (; counter <= n; ) {
            std::unique_lock<std::mutex> lck(mtx);
            if (counter % 3 != 0 && counter % 5 == 0) {
                printBuzz();
                counter++;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        for (; counter <= n; ) {
            std::unique_lock<std::mutex> lck(mtx);
            if (counter % 3 == 0 && counter % 5 == 0) {
                printFizzBuzz();
                counter++;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (; counter <= n; ) {
            std::unique_lock<std::mutex> lck(mtx);
            if (counter % 3 != 0 && counter % 5 != 0) {
                printNumber(counter);
                counter++;
                cv.notify_all();
            } else {
                cv.wait(lck);
            }
        }
    }
};

void fizz() {
    cout << "fizz\n";
}

void buzz() {
    cout << "buzz\n";
}

void fizzbuzz() {
    cout << "fizzbuzz\n";
}

void number(int i) {
    cout << i << endl;
}


int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int n = 0;
        cin >> n;

        FizzBuzz fb(n);


        const int threadnum = 4;
        std::thread threads[threadnum];

        threads[0] = std::thread([&fb] {fb.fizz(fizz); });
        threads[1] = std::thread([&fb] {fb.buzz(buzz); });
        threads[2] = std::thread([&fb] {fb.fizzbuzz(fizzbuzz); });
        threads[3] = std::thread([&fb] {fb.number(number); });

        for (int id = 0; id < threadnum; id++)
            threads[id].join();

        cout << endl;
    }
}