#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int cMaxN = 200000;
constexpr int cMaxTasks = 3;
unsigned long performance[cMaxN][cMaxTasks + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;

    unsigned long minimalWork = 0;
    unsigned long maxDurationForTasks = 0;
    unsigned long minDurationForTasks = -1;

    int longestWorkId = 0;

    for (int i = 0; i < n; ++i) {
        cin >> performance[i][0] >> performance[i][1] >> performance[i][2];
        performance[i][3] = performance[i][1] + performance[i][2];
        if (performance[i][3] > maxDurationForTasks) {
            maxDurationForTasks = performance[i][3];
            longestWorkId = i;
        }
        if (performance[i][3] < minDurationForTasks)
            minDurationForTasks = performance[i][3];
        minimalWork += performance[i][0];
    }

    if (maxDurationForTasks >= minimalWork) {
        cout << performance[longestWorkId][0] + maxDurationForTasks << endl;
    } else {
        cout << minimalWork + minDurationForTasks << endl;
    }
}