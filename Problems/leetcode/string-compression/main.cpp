#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0)
            return 0;

        char prev = chars[0];

        size_t pos = 0;
        size_t resLen = 0;
        size_t counter = 1;

        while (++pos < chars.size()) {
            const char current = chars[pos];
            if (current == prev) {
                // same symbol met
                counter++;
            } else {
                // new symbol met
                if (counter > 1) {
                    // conversion 123 into sequence '1','2','3'
                    stack<char> digits;
                    while (counter > 0) {
                        const size_t digit = counter % 10;
                        digits.push('0' + digit);
                        counter /= 10;
                    }
                    while (!digits.empty()) {
                        chars[++resLen] = digits.top();
                        digits.pop();
                    }
                    counter = 1;
                }
                chars[++resLen] = current;
                prev = current;
            }
        }

        // termination symbol met
        if (counter > 1) {
            // conversion 123 into sequence '1','2','3'
            stack<char> digits;
            while (counter > 0) {
                const size_t digit = counter % 10;
                digits.push('0' + digit);
                counter /= 10;
            }
            while (!digits.empty()) {
                chars[++resLen] = digits.top();
                digits.pop();
            }
        }
        ++resLen;

        return resLen;
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
        string str;
        while (str.empty())
            getline(cin, str);

        vector<char> data(str.length());
        transform(str.begin(), str.end(), data.begin(), [](char v) -> char { return v; });
        cout << s.compress(data) << endl;
    }

    return 0;
}