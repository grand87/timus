#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string convertToTitle(int v) {
        string res;
        while (v > 0) {
            int num = v % 26;
            if(num == 0)
                res.push_back('Z');
            else
                res.push_back('A' + num - 1);
            if (v == 26)
                break;
            if (num == 0)
                v -= 1;
            v /= 26;
        }
        //reverse res;

        for (int i = 0; i < res.length() / 2; i++) {
            swap(res[i], res[res.length() - 1 - i]);
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

       int val;
       cin >> val;

       Solution s;
       cout << s.convertToTitle(val).c_str() << endl;
   }
}