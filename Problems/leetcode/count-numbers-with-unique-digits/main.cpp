#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;

        int rst = 10;
        int count = 9;
        for (int i = 2; i <= n; i++) {
            count *= (10 - i + 1);
            rst += count;
        }
        return rst;
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
        cout << s.countNumbersWithUniqueDigits(n) << endl;
    }
}