/*
 * @author v.sharaienko (grandamx@gmail.com)
 */

#pragma comment(linker, "/STACK:16777216")

#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// #define ONLINE_JUDGE

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif

    int n, s, t;
    cin >> n >> s >> t;

    int times[101];

    const int maxExitTime = t + s;
    const int minEnterTime = t - s;

    int gandolsToProcess = 0;

    for (int i = 0; i < n; i++) {
        int _t;
        cin >> _t;
        
        // pre-optimise:
        // - exclude gandols which would exit from channel before time t
        // - exclude gandols which would enter into channel after time t + s
        if ((_t >= minEnterTime) && (_t <= maxExitTime)) {
            times[gandolsToProcess] = _t;
            gandolsToProcess++;
        }
    }

    for (int i = 0; i < gandolsToProcess; i++) {
        // calculate meet point with each gandol

        float meetT = t + (s + (times[i] - t)) * 0.5f;
        printf("%.5f\n", meetT);
    }

    return 0;
}
