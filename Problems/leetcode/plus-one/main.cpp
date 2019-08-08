#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <utils.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int acc = 1;
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++) {
            if (*it + acc == 10) {
                acc = 1;
                *it = 0;
            } else {
                *it += acc;
                acc = 0;
            }
        }
        vector<int> res;
        res.reserve(digits.size() + acc);
        if (acc)
            res.push_back(1);
        for (int a : digits)
            res.push_back(a);
        return res;
    }
};

int main()
{
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;
    Solution s;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        readVector(cin, v, n);
        vector<int> res = s.plusOne(v);
        printVector(cout, res);
        cout << endl;
    }

    return 0;
}
