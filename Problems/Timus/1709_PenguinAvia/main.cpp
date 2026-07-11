/*
 * @author vova sharaienko (grandamx@gmail.com)
 */

#pragma comment(linker, "/STACK:16777216")

#include <array>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// #define ONLINE_JUDGE

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif

    // idea is to search minimal path from each city to any city with electicity

    int distance[101][101];
    int minDistances[101];

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        minDistances[i] = -1;
    }
    for (int i = 0; i < k; i++) {
        int electroCity;
        cin >> electroCity;
        minDistances[electroCity] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int dist;
            cin >> dist;
            distance[i][j] = dist;
        }
    }


    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += minDistances[i];
    }

    cout << answer;

    return 0;
}
