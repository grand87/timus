#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

int buf[10000000];

class SlidingWindow {
    deque<int> data;
    int window;
    int localMax;
public:
    SlidingWindow(int size) : window(size) {
        localMax = -1;
    }

    void put(int val) {
        data.push_back(val);
        if (val > localMax)
            localMax = val;
        if (data.size() > window) {
            int front = data.front();
            data.pop_front();
            if (front == localMax) {
                //removed old max - need to locate new max
                localMax = *max_element(data.begin(), data.end());
            }
        }
    }

    int getLocalMax() const {
        return localMax;
    }
};

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        readArray(buf, n);

        SlidingWindow w(k);
        for (int j = 0; j < k; j++)
            w.put(buf[j]);
        cout << w.getLocalMax() << " ";
        for (int j = k; j < n; j++) {
            w.put(buf[j]);
            cout << w.getLocalMax() << " ";
        }

        cout << endl;
    }
    return 0;
}
