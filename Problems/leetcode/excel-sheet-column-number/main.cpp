#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        uint32_t res = 0;
        uint32_t base = 1;
        const uint32_t range = s.length();
        for (uint32_t i = 0; i < range; i++) {
            const uint32_t pos = range - i - 1;
            const uint32_t value = s[pos] - 'A' + 1;
            res += base * value;
            base *= 26;
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

       char buffer[1000];
       cin >> buffer;

       const string data(buffer);

       Solution s;
       cout << s.titleToNumber(data) << endl;
   }
}