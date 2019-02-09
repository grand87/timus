#include<iostream>
using namespace std;

int a1[1000000];
int a2[1000000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long n, m, k;
        cin >> n >> m >> k;

        for (int j = 0; j < n; j++)
            cin >> a1[j];

        for (int j = 0; j < m; j++)
            cin >> a2[j];

        long i1 = 0;
        long i2 = 0;
        long iTarget = 0;
        int lastValue = 0;;
        do {
            if (i1 < n && i2 < m) {
                if (a1[i1] < a2[i2]) {
                    lastValue = a1[i1];
                    i1++;
                }
                else {
                    lastValue = a2[i2];
                    i2++;
                }
            } else if (i1 < n) {
                lastValue = a1[i1];
                i1++;
            } else {
                lastValue = a2[i2];
                i2++;
            }

            iTarget++;
        } while (iTarget != k);
        cout << lastValue << endl;
    }
    return 0;
}