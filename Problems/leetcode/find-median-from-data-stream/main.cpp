#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_SIZE = 100000;

class MaxHeap {
    int size;
    vector<int> data;

    void siftdown() {
        for (int i = 1; i * 2 <= size;) {
            // select smallest child
            int c = i * 2;
            if (c + 1 <= size) {
                if (data[c + 1] > data[c])
                    c += 1;
            }
            if (data[i] < data[c]) {
                swap(data[i], data[c]);
                i = c;
            } else
                break;
        }
    }

    void siftup() {
        for (int i = size; i > 1; i = i / 2) {
            if (data[i] > data[i / 2])
                swap(data[i], data[i / 2]);
            else
                break;
        }
    }

public:
    MaxHeap() : size(0), data(MAX_SIZE) {
        data[0] = 0;
    }

    void reset() {
        size = 0;
    }

    void add(int value) {
        size++;
        data[size] = value;
        siftup();
    }

    int top() {
        if (size == 0)
            throw out_of_range("heap is empty");
        return data[1];
    }

    void pop() {
        if (size == 0)
            throw out_of_range("heap is empty");
        if (size > 1) {
            data[1] = data[size];
            size--;
            siftdown();
        }
    }

    int length() const {
        return size;
    }
};

class MinHeap {
    int size;
    vector<int> data;

    void siftdown() {
        for (int i = 1; i * 2 <= size;) {
            // select smallest child
            int c = i * 2;
            if (c + 1 <= size) {
                if (data[c + 1] < data[c])
                    c += 1;
            }
            if (data[i] > data[c]) {
                swap(data[i], data[c]);
                i = c;
            } else
                break;
        }
    }

    void siftup() {
        for (int i = size; i > 1; i = i / 2) {
            if (data[i] < data[i / 2])
                swap(data[i], data[i / 2]);
            else
                break;
        }
    }

public:
    MinHeap() : size(0), data(MAX_SIZE) {
        data[0] = 0;
    }

    void reset() {
        size = 0;
    }

    void add(int value) {
        size++;
        data[size] = value;
        siftup();
    }

    int top() {
        if (size == 0)
            throw out_of_range("heap is empty");
        return data[1];
    }

    void pop() {
        if (size == 0)
            throw out_of_range("heap is empty");
        if (size > 1) {
            data[1] = data[size];
            size--;
            siftdown();
        }
    }

    int length() const {
        return size;
    }
};

class MedianFinder {
    MinHeap upperhalf;
    MaxHeap lowerhalf;

    int size;

public:
    /** initialize your data structure here. */
    MedianFinder() : size(0) {
    }

    void addNum(int num) {
        if (size == 0)
            lowerhalf.add(num);
        else {
            if (num < lowerhalf.top()) {
                lowerhalf.add(num);
            } else {
                upperhalf.add(num);
            }
        }

        if (lowerhalf.length() > upperhalf.length() + 1) {
            upperhalf.add(lowerhalf.top());
            lowerhalf.pop();
        } else if (upperhalf.length() > lowerhalf.length() + 1) {
            lowerhalf.add(upperhalf.top());
            upperhalf.pop();
        }
        size++;
    }

    double findMedian() {
        if (size & 1)
            return lowerhalf.length() > upperhalf.length() ? lowerhalf.top() : upperhalf.top();
        else
            return (lowerhalf.top() + upperhalf.top()) / 2.0;
    }

    void reset() {
        upperhalf.reset();
        lowerhalf.reset();

        size = 0;
    }
};

class MedianFinderSort {
    vector<int> data;

public:
    /** initialize your data structure here. */
    MedianFinderSort() {
    }

    void addNum(int num) {
        data.push_back(num);
    }

    double findMedian() {
        sort(data.begin(), data.end());
        const int size = data.size();
        bool isOdd = size & 1;
        if (isOdd)
            return data[size / 2];
        else
            return (data[(size - 1) / 2] + data[size / 2]) / 2.f;
    }

    void reset() {
        data.clear();
    }
};

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    MedianFinder mf;
    // test 1
    mf.addNum(1);
    mf.addNum(2);
    assert(mf.findMedian() == 1.5);
    mf.addNum(3);
    assert(mf.findMedian() == 2);
    mf.reset();

    // test 2
    mf.addNum(6);
    assert(mf.findMedian() == 6.0);
    mf.addNum(10);
    assert(mf.findMedian() == 8.0);
    mf.addNum(2);
    assert(mf.findMedian() == 6.0);
    mf.addNum(6);
    assert(mf.findMedian() == 6.0);
    mf.addNum(5);
    assert(mf.findMedian() == 6.0);
    mf.addNum(0);
    assert(mf.findMedian() == 5.5);
    mf.addNum(6);
    assert(mf.findMedian() == 6.0);
    mf.addNum(3);
    assert(mf.findMedian() == 5.5);
    mf.addNum(1);
    assert(mf.findMedian() == 5.0);
    mf.addNum(0);
    assert(mf.findMedian() == 4.0);
    mf.addNum(0);
    assert(mf.findMedian() == 3.0);
    mf.reset();

    //test 3
    mf.addNum(-1);
    assert(mf.findMedian() == -1.0);
    mf.addNum(-2);
    assert(mf.findMedian() == -1.5);
    mf.addNum(-3);
    assert(mf.findMedian() == -2.0);
    mf.addNum(-4);
    assert(mf.findMedian() == -2.5);
    mf.addNum(-5);
    assert(mf.findMedian() == -3.0);

    return 0;
}
