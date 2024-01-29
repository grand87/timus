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
    string addBinary(string a, string b) {
        string result;
        result.reserve(a.size() + b.size());

        const bool isNum1Bigger = a.size() > b.size();

        string &v1 = isNum1Bigger ? a : b;
        string &v2 = isNum1Bigger ? b : a;

        int carry = 0;
        for (int i = 0; i < v1.size(); i++) {
            int localSum = v1[v1.size() - i - 1] + carry - '0';
            if (i < v2.size()) {
                localSum += v2[v2.size() - i - 1] - '0';
            }
            if (localSum > 1) {
                carry = 1;
                localSum = localSum - 2;
            }
            else
                carry = 0;
            result.push_back(localSum + '0');
        }

        if (carry)
            result.push_back('1');

        reverse(result.begin(), result.end());

        return result;
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
        string a, b;
        cin >> a >> b;
        Solution s;
        cout << s.addBinary(a, b) << endl;
    }
}