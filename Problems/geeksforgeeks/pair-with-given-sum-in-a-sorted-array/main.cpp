#include <iostream>
#include <algorithm>

using namespace std;

int dataArray[10000000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, value;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> dataArray[j];
        cin >> value;

        int pCount = 0;
        for (int j = 0; j < n - 1; j++) {
            const int r = value - dataArray[j];
            if (r <= dataArray[j])
                continue;

            if (binary_search(dataArray + j + 1, dataArray + n, r)) {
                pCount++;
                cout << dataArray[j] << " " << r << " " << value << endl;
            }
        }
        if(pCount == 0)
            cout << "-1" << endl;
    }
    return 0;
}