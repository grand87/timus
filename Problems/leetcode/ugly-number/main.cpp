#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

public:
    bool isUgly(int num) {
        if (num < 0)
            return false;
        while (num != 1) {
            const int t = num;
            if (num % 5 == 0)
                num /= 5;
            if (num % 3 == 0)
                num /= 3;
            if (num % 2 == 0)
                num /= 2;
            if (num == t)
                return false;
        }
        return true;
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
        cout << s.isUgly(n) << endl;
    }
    return 0;
}