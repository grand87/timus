#include<iostream>
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

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        const int minimal = min(min(a, b), c);
        const int maximal = max(max(a, b), c);
        cout << a + b + c - maximal - minimal << endl;
    }
    return 0;
}
