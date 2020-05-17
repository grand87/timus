#include <assert.h>
#include <utils.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long l = 0;
        long r = x;
        long m = 0;

        while (l <= r) {
            m = l + (r - l) / 2;
            const long res = m * m;

            if (res > x) {
                r = m - 1;
            } else if (res < x) {
                l = m + 1;
            } else
                return m;
        }

        return l - 1;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    Solution s;

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;

        cout << s.mySqrt(x) << endl;
    }

    return 0;
}