#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    vector<char> v[2];
    vector<char> f[2];

public:
    bool canWinHelper(int n, bool fPlayer) {
        if (n <= 3) {
            return true;
        }

        if (!f[fPlayer][n]) {
            f[fPlayer][n] = true;
            v[fPlayer][n] = !(canWinHelper(n - 1, !fPlayer) &&
                              canWinHelper(n - 2, !fPlayer) &&
                              canWinHelper(n - 3, !fPlayer));
        }

        return v[fPlayer][n];
    }


    bool canWinNim(int n) {
        if (n < 4)
            return true;

        v[0].resize(n+1);
        v[1].resize(n+1);

        for (int i = 0; i < n + 1; i++) {
            f[0][i] = false;
            f[1][i] = false;
        }

        bool res = canWinHelper(n, true);
        return v[1][n];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;

    Solution s;
    int n;

    assert(s.canWinNim(3));
    assert(s.canWinNim(4) == false);
    assert(s.canWinNim(5));
    assert(s.canWinNim(6));

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << s.canWinNim(n) << endl;
    }
}