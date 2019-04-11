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

int buf[10000000];

class Container {
    int a[2];
    int size = 0;
public:
    Container() : size{ 0 }, a{0,0} {
        
    }

    void put(int val) {
        if (val > a[0]) {
            a[1] = a[0];
            a[0] = val;
        }
        else if (val > a[1])
            a[1] = val;
    }

    int getProduct() {
        return a[0] * a[1];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        readArray(buf, n);
        //need to locate 2 biggest items - we could use priority queue for it - and keep only 2 items
        Container c;
        for (int j = 0; j < n; j++)
            c.put(buf[j]);
        cout << c.getProduct() << endl;
    }
    return 0;
}