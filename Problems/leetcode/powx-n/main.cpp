#include <assert.h>
#include <utils.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;

        if (n == 0)
            return 1;

        if (n == 1)
            return x;

        if (n == -1)
            return 1 / x;

        if (n == 2)
            return x * x;

        if (n == 2)
            return 1 / (x * x);

        double res = 0;

        if (n % 2 == 0) {
            res = myPow(x * x, n / 2);
        }
        else
            res = myPow(x * x, (n - 1) / 2) * x;

        return res;
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
        double x;
        cin >> x;
        int n;
        cin >> n;

        cout << s.myPow(x, n) << endl;
    }

    return 0;
}