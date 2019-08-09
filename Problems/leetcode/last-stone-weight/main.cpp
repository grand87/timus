#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class MaxHeap {
    vector<int> data;
    int count;

    void siftup() {
        for (int i = count; i > 1;) {
            if (data[i / 2] < data[i]) {
                swap(data[i / 2], data[i]);
                i /= 2;
            } else
                break;
        }
    }

    void siftdown() {
        for (int i = 1; i * 2 <= count;) {
            int cIndex = i * 2;
            if (cIndex + 1 <= count) {
                if (data[cIndex] < data[cIndex + 1]) {
                    cIndex++;
                }
            }

            if (data[i] < data[cIndex]) {
                swap(data[i], data[cIndex]);
                i = cIndex;
            } else
                break;
        }
    }

public:
    MaxHeap(int size) : data(size + 1), count(0) {
    }

    void add(int val) {
        count++;
        data[count] = val;
        siftup();
    }

    int top() const {
        if (count == 0)
            throw out_of_range("empty heap");

        return data[1];
    }

    void pop() {
        if (count == 0)
            throw out_of_range("empty heap");

        data[1] = data[count];
        count--;
        siftdown();
    }

    int size() const {
        return count;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        MaxHeap heap(stones.size());

        for (int v : stones) {
            heap.add(v);
        }

        while (heap.size() > 1) {
            int s1 = heap.top();
            heap.pop();

            int s2 = heap.top();
            heap.pop();

            if (s1 != s2) {
                int diff = abs(s1 - s2);
                heap.add(diff);
            }
        }

        if (heap.size() == 1)
            return heap.top();
        else
            return 0;
    }
};

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> data(n);
        readVector<int>(cin, data, n);

        Solution s;
        cout << s.lastStoneWeight(data) << endl;
        cout << endl;
    }
    return 0;
}