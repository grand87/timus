#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> expr;

        if (s.length() == 0)
            return true;

        for (char c : s) {
            switch (c) {
            case '(' :
            case '[':
            case '{':
                expr.push(c);
                break;
            case ')':
                if (expr.size() && expr.top() == '(')
                    expr.pop();
                else
                    return false;
                break;
            case ']':
                if (expr.size() && expr.top() == '[')
                    expr.pop();
                else
                    return false;
                break;
            case '}':
                if (expr.size() && expr.top() == '{')
                    expr.pop();
                else
                    return false;
                break;
            }
        }
        return expr.size() == 0;
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

        char buf[1024];
        cin >> buf;
        string str(buf);

        Solution s;
        cout << str.c_str() << " - " << s.isValid(str) << endl;
    }
}