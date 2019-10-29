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
    string addStrings(string num1, string num2) {
        const bool isALonger = num1.size() > num2.size();
        string &a = isALonger ? num1 : num2;
        string &b = isALonger ? num2 : num1;

        if (a.size() == 1 && a[0] == '0')
            return b;
        if (b.size() == 1 && b[0] == '0')
            return a;

        //reduce -'0' operation
        for (char & c : a)
            c -= '0';
        for (char & c : b)
            c -= '0';

        string result;
        result.reserve(num1.size() + num2.size() + 2);

        int carry = 0;
        for (int i = 0; i < a.size(); i++) {
            int localSum = a[a.size() - i - 1] + carry;
            if (i < b.size()) {
                localSum += b[b.size() - i - 1];
            }
            if (localSum > 9) {
                carry = 1;
                localSum -= 10;
            }
            else
                carry = 0;
            result.push_back(localSum + '0');
        }
        if(carry)
            result.push_back(carry + '0');

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
        cout << s.addStrings(a, b) << endl;
    }
}