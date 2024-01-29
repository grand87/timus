#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(int n) {
    int ones = 0;
    int maxOnes = 0;
    while (n > 0) {
        if (n & 0b1) {
            ones++;
            maxOnes = max(maxOnes, ones);
        } else {
            ones = 0;
        }
        n >>= 1;    
    }

    return maxOnes;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; ++t) {
        int n, ans;
        cin >> n >> ans;

        const int res = solve(n);

        cout << res << (res == ans ? " - OK" : " - Fail") << endl;
    }
    return 0;
}