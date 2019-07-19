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
public:
    string removeOuterParentheses(string S) {
        
        typedef stack<char> Expr;
        typedef vector<Expr> ExprList;

        ExprList expr(50);

        int levels = 0;
        stringstream ss(S);

        stringstream res;

        char s;
        while (ss >> s) {
            if (s == '(') {
                if (expr[levels].size() > 0 && expr[levels].top() == '(') {
                    levels++;
                }
                expr[levels].push('(');
                if (levels > 0)
                    res << "(";
            } else if (s == ')') {
                if (expr[levels].top() == ')') {
                    //close current level & move-up
                    levels--;
                }
                expr[levels].push(')');
                if(levels > 0)
                    res << ")";
            }
        }
        
        return res.str();
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
        char srcbuf[255];
        char refbuf[255];
        cin >> srcbuf >> refbuf;

        Solution s;
        string res(srcbuf);
        res = s.removeOuterParentheses(res);
        cout << res.c_str();
        if ((res.length() == 0 && refbuf[0] == 'e') || strcmp(res.c_str(), refbuf) == 0)
            cout << " correct";
        else
            cout << " error";
        cout << endl;
    }
}