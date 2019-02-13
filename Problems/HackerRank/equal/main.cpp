#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    //here need to precalculate the table for how how many operations are required to make N to 0
    int table[1001] = {-1};

    table[0] = 0;
    table[1] = 1;
    table[2] = 1;
    table[3] = 2;
    table[4] = 2;
    table[5] = 1;

    for (int i = 6; i < 1001; i++) {
        table[i] = min(1 + table[i - 5], 1 + min(1 + table[i - 2], 1 + table[i - 1]));
    }

    int c = table[13];

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> a[j];

        //check is there values differs from 1,2,5
        int ops = 0;
        for (int j = 0; j < n; j++) {
            ops += table[a[j]];
        }


        int minVal = a[0];
        for (int j = 1; j < n; j++) {
            if (a[j] < minVal)
                minVal = a[j];
        }

        if (minVal != 1) {
            for (int j = 0; j < n; j++) {
                a[j] -= minVal;
            }
        }

        int ops2 = 0;
        for (int j = 0; j < n; j++) {
            ops2 += table[a[j]];
        }
        cout << min(ops, ops2) << endl;
    }

    return 0;
}
