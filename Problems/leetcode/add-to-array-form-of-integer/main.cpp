#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
    typedef vector<int>::reverse_iterator vecri;

    public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        int acc = 0;
        for (vecri it = a.rbegin(); it != a.rend(); it++) {
            if (k == 0 && acc == 0)
                break;
            acc += k % 10;
            k /= 10;

            if (*it + acc >= 10) {
                *it += acc - 10;
                acc = 1;
            } else {
                *it += acc;
                acc = 0;
            }
        }

        vector<int> res;
        k += acc;
        while (k != 0) {
            res.push_back(k % 10);
            k /= 10;
        }

        //reverse
        for (int i = 0; i < res.size() / 2; i++) {
            swap(res[i], res[res.size() - i - 1]);
        }

        for (int v : a)
            res.push_back(v);

        return res;
    }
};

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;
    Solution s;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        readVector(cin, v, n);
        vector<int> res = s.addToArrayForm(v, k);
        printVector(cout, res);
        cout << endl;
    }

    return 0;
}
