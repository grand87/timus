#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

    static const int bitsCount[16];

    int bitsIn32(int val) {
        int count = 0;
        while (val > 0) {
            count += bitsCount[val & 0b1111];
            val >>= 4;
        }
        return count;
    }

    bool* genPrimes(int n) {
        bool* res = new bool[n + 1];
        res[0] = false;
        res[1] = false;
        for (int i = 2; i < n; i++)
            res[i] = true;

        for (int i = 2; i * i < n; i++) {
            for (int j = i; j <= n / i; j++) {
                res[i * j] = false;
            }
        }

        return res;
    }

public:
    int countPrimeSetBits(int L, int R) {
        const bool* primes = genPrimes(40);

        int res = 0;
        for (int i = L; i <= R; i++) {
            int const bits = bitsIn32(i);
            res += primes[bits];

            cout << i << " " << bits << " " << res << endl;
        }

        delete[] primes;

        return res;
    }
};

const int Solution::bitsCount[16] = {
    0,  // 0000b
    1,  // 0001b
    1,  // 0010b
    2,  // 0011b
    1,  // 0100b 
    2,  // 0101b
    2,  // 0110b
    3,  // 0111b
    1,  // 1000b
    2,  // 1001b
    2,  // 1010b
    3,  // 1011b
    2,  // 1100b 
    3,  // 1101b
    3,  // 1110b
    4  // 1111b
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
        cin >> n >> m;

        Solution s;
        cout << s.countPrimeSetBits(n, m) << endl;
    }
    return 0;
}