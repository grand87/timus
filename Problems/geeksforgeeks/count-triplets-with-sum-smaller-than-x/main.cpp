#include<iostream>
#include<algorithm>

using namespace std;

void readArray(long* data, unsigned long size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

long buf[10000000];

int countTriplets(long* data, unsigned long size, long value) {
    unsigned long res = 0;
    sort(data, data + size);

    for (int i = 0; i < size - 2; i++) {
        int j = i + 1;
        int k = size - 1;
        while (j < k) {
            const long sum = data[i] + data[j] + data[k];
            if (sum < value) {
                res += k - j;
                j++;
            } else {
                k--;
            }
        }
    }

    return res;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unsigned long n, val;
        cin >> n >> val;
        readArray(buf, n);
        cout << countTriplets(buf, n, val) << endl;
    }
    return 0;
}