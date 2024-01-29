#include<iostream>

using namespace std;

void readArray(unsigned long* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

const unsigned long diff = 1000002;
unsigned long buf[1000001];

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
        buf[n] = 0;
        for (int j = 0; j < n; j++) {
            const int index = buf[j] % diff;
            buf[index] += diff;
        }

        unsigned long missing = 0;
        unsigned long twice = 0;

        for (int j = 1; j <= n; j++) {
            if (buf[j] < diff)
                missing = j;
            else if (buf[j] / diff >= 2)
                twice = j;
        }

        cout << twice << " " << missing;

        cout << endl;
    }
    return 0;
}
