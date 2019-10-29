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
    string multiply(string num1, string num2) {
        //determine who is bigger
        bool isABigger = num1.size() > num2.size();
        const string& a = isABigger ? num1 : num2;
        const string& b = isABigger ? num2 : num1;

        if (b.size() == 1) {
            if (b[0] == '0')
                return "0";
            if (b[0] == '1')
                return a;
        }

        vector<vector<int>> ir(b.size());
        int l = 0;
        int maxDigits = 0;
        for (string::const_reverse_iterator itB = b.rbegin(); itB != b.rend(); itB++) {
            for (int i = 0; i < l; i++)
                ir[l].push_back(0);
           
            int carry = 0;
            const int diggit = (*itB) - '0';
            //TODO: add optimization if digit == 1 or diggit == 0
            for (string::const_reverse_iterator itA = a.rbegin(); itA != a.rend(); itA++) {
                int mul = ((*itA) - '0') * diggit + carry;
                if (mul > 9) {
                    carry = mul / 10;
                    mul = mul % 10;
                }
                else
                    carry = 0;
                ir[l].push_back(mul);
            }
            if(carry)
                ir[l].push_back(carry);
            maxDigits = max(maxDigits, (int)ir[l].size());
            l++;
        }

        //sum-up ir
        vector<int> res;
        int carry = 0;
        for (int d = 0; d < maxDigits; d++) {
            int columnSum = carry;
            for (int i = 0; i < ir.size(); i++) {
                if (ir[i].size() > d) {
                    columnSum += ir[i][d];
                }
            }
            if (columnSum > 9) {
                carry = columnSum / 10;
                columnSum = columnSum % 10;
            }
            else
                carry = 0;
            res.push_back(columnSum);
        }
        if(carry)
            res.push_back(carry);

        string result;

        for (vector<int>::const_reverse_iterator it = res.rbegin(); it != res.rend(); it++)
            result.push_back(*it + '0');

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
        cout << s.multiply(a, b) << endl;
    }
}