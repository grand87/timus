#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1 << 31;

        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (n > 0) {
                int bit = n & 1;
                res = (res << 1) | bit;
            } else {
                res <<= 32 - i;
                break;
            }
            n = n >> 1;
        }
        return res;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
#endif

   int t = 0;
   cin >> t;
   for (int i = 0; i < t; i++) {

       uint32_t n = 0;
       cin >> n;

       Solution s;
       cout << s.reverseBits(n) << endl;
   }
}