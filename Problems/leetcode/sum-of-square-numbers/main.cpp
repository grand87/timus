#include <assert.h>
#include <utils.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {

        const long sq = sqrt(c);

        for (long a = sq; a >= 0; a--) {
            
            const long sq1 = a * a;

            for (long b = sqrt(c - sq1); b >= 0; b--) {
                
                const long res = sq1 + b * b;
                
                if (res == c)
                    return true;
                
                if (res < c)
                    break;
            }
        }
        return false;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    Solution s;

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int v;
        cin >> v;

        cout << s.judgeSquareSum(v) << endl;
    }

    return 0;
}