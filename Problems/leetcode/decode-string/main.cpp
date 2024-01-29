#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    int pos;

    int readNumber(string &s) {
        char buf[255];
        int len = 0;
        do {
            buf[len++] = s[pos++];
        } while (isdigit(s[pos]));
        buf[len] = 0;
        return atoi(buf);
    }

    string readString(string &s) {
        char buf[255];
        int len = 0;
        do {
            buf[len++] = s[pos++];
        } while (islower(s[pos]) || isupper(s[pos]));
        buf[len] = 0;
        return string(buf);
    }

public:
    Solution() {
        pos = 0;
    }

    string decodeString(string s) {
        //need to unparse source string as number and substring to be repeated for example 2[ab] == > 2 & ab

        stack<int> number;
        stack<string> str;
        
        while(pos < s.size()) {
            if (isdigit(s[pos])) {
                number.push(readNumber(s));
                pos++; // read '['
                str.push(decodeString(s));
            } else if (s[pos] == ']') {
                pos++;
                break;
            } else if (islower(s[pos]) || isupper(s[pos])) {
                number.push(1);
                str.push(readString(s));
            }
        }

        string result;
        while (!str.empty()) {
            const string tmp = str.top();
            str.pop();

            
            int count = 1;
            if (!number.empty()) {
                count = number.top();
                number.pop();
            }

            for (int i = 0; i < count; i++) {
                result = tmp + result;
            }
        }

        return result;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        char buf[255];
        cin >> buf;
        string str(buf);
        Solution s;
        cout << s.decodeString(str).c_str() << endl;
    }
}