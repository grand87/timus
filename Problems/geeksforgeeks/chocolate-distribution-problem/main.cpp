#include <iostream>
#include <algorithm>

using namespace std;

long long packs[10000001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> packs[j];
        }
        int m;
        cin >> m;

        sort(packs, packs + n);

        //implement sliding window
        long long minDiff = packs[m - 1] - packs[0];
        for (int j = 1; j < n - m + 1; j++) {
            const long long diff = packs[j + m - 1] - packs[j];
            if (diff < minDiff)
                minDiff = diff;
        }

        cout << minDiff << endl;
    }
    return 0;
}