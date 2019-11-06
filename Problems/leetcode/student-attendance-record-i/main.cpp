#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int lates = 0;
        int absent = 0;
        for (char c : s) {
            if (c == 'L') {
                lates++;
                if (lates > 2)
                    return false;
            } else {
                if (c == 'A') {
                    absent++;
                    if (absent > 1)
                        return false;
                }
                lates = 0;
            }
        }

        return true;
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
        string a;
        cin >> a;
        Solution s;
        cout << s.checkRecord(a) << endl;
    }
}