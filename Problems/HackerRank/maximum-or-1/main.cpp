#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_N = 101;
constexpr int MAX_K = 101;

long long solve(const string& L, int k) {
    const int n = L.size();
    unsigned long long dp[MAX_N][2][MAX_K];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 2; j++)
            for (int x = 0; x <= k; x++)
                dp[i][j][x] = 0;

    vector<int> s;
    for (char c : L)
        s.push_back(c - '0');

    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i) {
        int sm = 0;
        while (sm < 2) {
            for (int j = 0; j < k + 1; ++j) {
                int x = 0;
                while (x <= (sm ? 9 : s[i])) {
                    dp[i + 1][sm || x < (s[i])][j + (x > 0)] += dp[i][sm][j];
                    dp[i + 1][sm || x < (s[i])][j + (x > 0)] %= 1000000007;
                    ++x;
                }
            }
            ++sm;
        }
    }

    return (dp[n][0][k] + dp[n][1][k]) % 1000000007;
}

int getNumberOfIntegers(string L, string R, int k) {
    return (solve(R, k) - solve(L, k)) % 1000000007;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; ++t) {
        string l, r;
        while (l.size() == 0)
            getline(cin, l);

        while (r.size() == 0)
            getline(cin, r);

        int k = 0, ans = 0;
        cin >> k >> ans;

        const int res = getNumberOfIntegers(l, r, k);

        cout << res << (res == ans ? " - OK" : " - Fail") << endl;
    }
    return 0;
}