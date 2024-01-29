#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minimumMoves(string s, int d) {
    // count consequitive zeros in dp
    unsigned int totalMoves = 0;
    unsigned int rangeLen = 0;

    unsigned int p = 0;
    while (p < s.size()) {
        if (s[p] == '1') {
            if (rangeLen != 0) {
                totalMoves += rangeLen / d;
                rangeLen = 0;
            }
        } else {
            rangeLen++;
        }
        p++;
    }

    if (rangeLen != 0) {
        totalMoves += rangeLen / d;
    }

    return totalMoves;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; ++t) {
        string line;
        while (line.size() == 0)
            getline(cin, line);
        int d = 0, ans = 0;
        cin >> d >> ans;

        const int res = minimumMoves(line, d);

        cout << res << (res == ans ? " - OK" : " - Fail") << endl;
    }
    return 0;
}