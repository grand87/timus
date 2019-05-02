#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

    int _atoi(const char* str, int size, bool &isOverflow) {
        int res = 0;
        for (int i = 0; i < size; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                if (res > INT_MAX / 10) {
                    isOverflow = true;
                    return INT_MAX;
                }
                res = res * 10;
                int digit = str[i] - '0';

                //cout << res << " " << digit << " " << max << endl;
                if (res <= INT_MAX - digit)
                    res += digit;
                else {
                    isOverflow = true;
                    return INT_MAX;
                }
            }
            else
                break;
        }
        return res;
    }

public:
    int myAtoi(string str) {
        //discard white spaces
        int pos = 0;
        while (str[pos] == ' ')
            pos++;

        if (pos == str.length())
            return 0;

        int res = 0;
        bool flag = false;
        if (str[pos] == '-') {
            res = _atoi(str.c_str() + 1 + pos, str.length() - 1, flag);
            if (res == INT_MAX && flag)
                return INT_MIN;
            else
                return -res;
        }
        else {
            if (str[pos] == '+')
                pos++;

            res = _atoi(str.c_str() + pos, str.length(), flag);
            return res;
        }
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

       char buf[256];
       cin >> buf;

       Solution s;
       cout << s.myAtoi(buf) << endl;
   }
}