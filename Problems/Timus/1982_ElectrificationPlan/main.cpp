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
#include <stdbool.h>

using namespace std;

// #define ONLINE_JUDGE

// idea is to find minimal path from each city to any city with electicity
int distances[101][101];
int minDistances[101];

int findMinimal(int source, int n) {
    int result = -1;
    int visited[101];
    int minToCity[101];

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        minToCity[i] = -1;
    }
    minToCity[source] = 0;
    visited[source] = true;

    vector<pair<int, int>> toVisit;
    for (int i = 1; i <= n; i++) {
        if (i == source) {
            continue;
        }
        toVisit.push_back({source, i});
    }

    while (toVisit.size()) {
    
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif


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
            distances[i][j] = dist;
        }
    }

    

    for (int i = 1; i <= n; i++) {
        // find shortest path from city I to any city with electricity
        // via looping via all other cities reusing info about min distance
        // from accumulated minDistances

        if (minDistances[i] == -1) {
            // not visited yet
            minDistances[i] = findMinimal(i, n);
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += minDistances[i];
    }

    cout << answer;

    return 0;
}
