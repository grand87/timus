#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;

int gcd(int a, int b) {
    if (a == b)
        return b;
    while (b != 0) {
        a = a % b;
        if (a < b)
            swap(a, b);
    }

    return a;
}

class Solution {
    bool divisorGameHelper(int N, unordered_map<int, bool> &cache, int player) {
        if (cache.find(N) != cache.end())
            return cache[N];

        /*2 options:
                -  we will took biggest odd number
                -  we will took biggest even number
        */
        int gcd1 = gcd(N, N - 1);
        int gcd2 = gcd(N, N - 2);

        bool s1 = false;
        if (cache.find(N - gcd1) != cache.end())
            s1 = cache[N - gcd1];
        else {
            s1 = divisorGameHelper(N - gcd1, cache, !player);
            cache[N - gcd1] = s1;
        }

        if (s1 && player == 1)
            return false;
        if (s1 && player == 0)
            return true;

        bool s2 = false;
        if (cache.find(N - gcd2) != cache.end())
            s2 = cache[N - gcd2];
        else {
            s2 = divisorGameHelper(N - gcd2, cache, !player);
            cache[N - gcd2] = s2;
        }

        if (s2 && player == 1)
            return false;
        if (s2 && player == 0)
            return true;

        return false;
    }

public:
    bool divisorGame2(int N) {
        unordered_map<int, bool> cache;
        cache[1] = false;
        cache[2] = true;
        cache[3] = false;

        int gamer = 0;
        for (int i = 4; i <= N; i++) {
            if (gamer == 1) {
                if (cache[i - 1] || cache[i - 2]) {
                    cache[i] = false;
                }
            } else {
                cache[i] = cache[i - 1] || cache[i - 2];
            }
            gamer = !gamer;
        }

        return cache[N];
    }


    bool divisorGame(int N) {
        bool result = divisorGame2(N);
#ifdef LOCAL_TEST
        unordered_map<int, bool> cache;
        cache[1] = false;
        cache[2] = true;
        cache[3] = false;

        if (cache.find(N) != cache.end())
            return cache[N];

        assert(result == divisorGameHelper(N, cache, 0));
#endif
        return result;
    }
};

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        Solution s;
        cout << s.divisorGame(n) << endl;
    }
}