#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int cMaxN = 200000;
constexpr int cMaxTasks = 3;

struct work {
    unsigned long a;
    unsigned long b;
    unsigned long startB;
    unsigned long endB;
};

work performance[cMaxN];

unsigned long solve(long n) {
    unsigned long minimalWork = 0;
    unsigned long maxDurationForTasks = 0;
    unsigned long minDurationForTasks = -1;

    unsigned long a, b;

    int longestWorkId = 0;

    for (int i = 0; i < n; ++i) {

        cin >> performance[i].a >> a >> b;
        performance[i].b = a + b;
        if (performance[i].b > maxDurationForTasks) {
            maxDurationForTasks = performance[i].b;
            longestWorkId = i;
        }
        if (performance[i].b < minDurationForTasks)
            minDurationForTasks = performance[i].b;
        minimalWork += performance[i].a;
    }

    unsigned long result = 0;

    if (maxDurationForTasks >= minimalWork) {
        result = performance[longestWorkId].a + maxDurationForTasks;
    } else {
        result = minimalWork + minDurationForTasks;
    }
    return result;
}

bool compareWork(const work& a, const work& b) {
    return a.b > b.b;
}

unsigned int solveSort(int n) {
    unsigned long a, b;
    for (int i = 0; i < n; ++i) {
        cin >> performance[i].a >> a >> b;
        performance[i].b = a + b;
    }

    sort(performance, performance + n, compareWork);
    
    performance[0].startB = performance[0].a;
    performance[0].endB = performance[0].startB + performance[0].b;

    a = performance[0].endB;
    for (int i = 1; i < n; ++i) {
        performance[i].startB = performance[i-1].startB + performance[i].a;
        performance[i].endB = performance[i].startB + performance[i].b;
        if (performance[i].endB > a)
            a = performance[i].endB;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;

    unsigned long result = solveSort(n);

    cout << result << endl;
}