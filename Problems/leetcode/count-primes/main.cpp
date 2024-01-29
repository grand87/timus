#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    bool* fillPrimes(int n) {
        bool *result = new bool[n + 1];

        for (int i = 0; i < n; i++) {
            result[i] = true;
        }
        result[0] = false;
        result[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (!result[i])
                continue;
            for (int j = i; j <= n / i; j++) {
                result[i * j] = false;
            }
        }

        return result;
    }

public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;

        bool* primes = fillPrimes(n);
        int count = 0;
        for (int i = 2; i < n; i++) {
            count += primes[i];
        }
        delete[] primes;
        return count;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n;

        Solution s;
        cout << s.countPrimes(n) << endl;
    }
    return 0;
}