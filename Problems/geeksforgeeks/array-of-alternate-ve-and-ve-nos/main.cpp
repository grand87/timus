#include<iostream>
#include<vector>

using namespace std;

void readArray(int* data, long long size) {
    for (long long i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, long long size) {
    for (long long i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void alternate(int* src, int* dst, long long size) {
    vector<int> pos;
    pos.reserve(size);
    vector<int> neg;
    neg.reserve(size);

    for (int i = 0; i< size; i++) {
        if (src[i] >= 0)
            pos.push_back(src[i]);
        else
            neg.push_back(src[i]);
    }

    int iNeg = 0;
    int iPos = 0;
    int i = 0;
    while (i < size) {
        if (iPos < pos.size()) {
            dst[i] = pos[iPos++];
            i++;
        }
        if (iNeg < neg.size()) {
            dst[i] = neg[iNeg++];
            i++;
        }
    }
}

int buf[10000000];
int result[10000000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        readArray(buf, n);
        alternate(buf, result, n);
        printArray(result, n);
    }
    return 0;
}