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
    int localMax;
    int window;
public:
    SlidingWindow(int size) : localMax{ -1 }, window(size) {
   
    }

    void put(int val) {
        data.push_back(val);
        if (data.size() > window)
            data.pop_front();
    }

    int getLocalMax() {
        make_heap(data.begin(), data.end());
        return data.front();
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
