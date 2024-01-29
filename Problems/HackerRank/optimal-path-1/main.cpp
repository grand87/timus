#include <utils.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<pair<int, int>>> DP;

void printMatrix(int x, int y, DP& matrix, int spacing = 5) {
    cout << endl;
    for (int r = 0; r < y; r++) {
        for (int c = 0; c < x; c++) {
            cout << setw(spacing) << matrix[r][c].first << "(" << matrix[r][c].second << ")";
        }
        cout << endl;
    }
}

void initDP(DP& dp, int r, int c) {
    dp.resize(r);
    for (auto& v : dp) {
        v.resize(c);
        fill(v.begin(), v.end(), make_pair(-1, 0));
    }
}

bool isValid(const pair<int, int>& v, int rows, int cols) {
    return v.first >= 0 && v.first < rows && v.second >= 0 && v.second < cols;
}

const int directions[]{0, 1, 0, -1, 0};

const int directionsCount = 4;

pair<int, int> getDirection(int i) {
    return make_pair(directions[i], directions[i + 1]);
}

pair<int, int> operator+(const pair<int, int>& v1, const pair<int, int>& dir) {
    return make_pair(v1.first + dir.first, v1.second + dir.second);
}

int getEnergy(const vector<vector<int>>& c, const pair<int, int>& v1, const pair<int, int>& v2) {
    return abs(c[v1.first][v1.second] - c[v2.first][v2.second]);
}

int getMinEffort(vector<vector<int>> c) {
    const int rows = c.size();
    const int cols = c[0].size();

    DP dp;
    initDP(dp, rows, cols);
    dp[0][0] = make_pair(0, 0);

#ifdef LOCAL_TEST
    printMatrix(cols, rows, dp);
#endif

    // bfs
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

#ifdef LOCAL_TEST
        cout << v.second << ":" << v.first << endl;
#endif

        // process neighbours
        for (int d = 0; d < directionsCount; ++d) {
            auto nextV = v + getDirection(d);

            if (isValid(nextV, rows, cols)) {
#ifdef LOCAL_TEST
                cout << "probe " << nextV.second << ":" << nextV.first;
#endif

                // cost to nextV from current cell
                const int newCost = getEnergy(c, v, nextV);
                const int maxEnergyOnCurrentPath = max(dp[v.first][v.second].second, newCost);

                // is it reasonable to visit nextV?
                if (dp[nextV.first][nextV.second].first == -1) {
                    // never visited
                    dp[nextV.first][nextV.second].first = newCost;
                    dp[nextV.first][nextV.second].second = maxEnergyOnCurrentPath;
                    if (!((nextV.first == rows - 1) && (nextV.second == cols - 1))) {
                        q.push(nextV);
#ifdef LOCAL_TEST
                        cout << " ADD" << endl;
#endif
                    }
#ifdef LOCAL_TEST
                    printMatrix(cols, rows, dp);
#endif
                } else {
                    // we already was here - so may be we come from more efficient way?
                    if ((maxEnergyOnCurrentPath < dp[nextV.first][nextV.second].second &&
                         newCost < dp[nextV.first][nextV.second].first) ||
                        (maxEnergyOnCurrentPath < dp[nextV.first][nextV.second].second &&
                         newCost <= maxEnergyOnCurrentPath)) {
                        // if (max(newCost, maxEnergyOnCurrentPath) <
                        //    max(dp[nextV.first][nextV.second].first, dp[nextV.first][nextV.second].second)) {
                        dp[nextV.first][nextV.second].first = newCost;
                        dp[nextV.first][nextV.second].second = maxEnergyOnCurrentPath;
                        // re-evaluate the path
                        if (!((nextV.first == rows - 1) && (nextV.second == cols - 1))) {
                            q.push(nextV);
#ifdef LOCAL_TEST
                            cout << " ADD" << endl;
#endif
                        }

#ifdef LOCAL_TEST
                        printMatrix(cols, rows, dp);
#endif
                    }
                }
            }
        }
    }

    return dp[rows - 1][cols - 1].second;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; ++t) {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> m;
        readMatrix(c, r, m);
        int ans;
        cin >> ans;

        const int res = getMinEffort(m);
        cout << endl << res << " - " << (res == ans ? "OK" : "FAIL") << endl;
    }
    return 0;
}