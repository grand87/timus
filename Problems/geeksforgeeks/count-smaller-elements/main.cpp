#include <iostream>
#include <algorithm>

using namespace std;

long long packs[1000001];

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

        for (int j = 0; j < n; j++) {
            int c = 0;
            for (int k = j + 1; k < n; k++) {
                if (packs[k] < packs[j])
                    c++;
            }
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}