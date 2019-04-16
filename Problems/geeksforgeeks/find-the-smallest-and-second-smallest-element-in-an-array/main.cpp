#include<iostream>

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

int buf[1000000];

class Heap {
    int buf[2];
public:
    Heap() : buf{ 5000, 5000 } {

    }

    void insert(int a) {
        if (a < buf[0]) {
            buf[1] = buf[0];
            buf[0] = a;
        }
        else if (a < buf[1] && a != buf[0]) {
            buf[1] = a;
        }
    }

    int getFirst() const {
        return buf[0];
    }

    int getSecond() const {
        return buf[1];
    }
};

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        readArray(buf, n);

        Heap heap;
        for (int j = 0; j < n; j++) {
            heap.insert(buf[j]);
        }
        if (heap.getFirst() == 5000 || heap.getSecond() == 5000)
            cout << -1 << endl;
        else
            cout << heap.getFirst() << " " << heap.getSecond() << endl;
    }
    return 0;
}