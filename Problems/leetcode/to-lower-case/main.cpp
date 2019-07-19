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
    void transform2(string::iterator aBegin, string::iterator aEnd, string::iterator bBegin) {
        while (aBegin != aEnd) {
            *bBegin = tolower(*aBegin);
            aBegin++;
            bBegin++;
        }
    }

public:
    string toLowerCase(string str) {
        string res(str);
        transform2(str.begin(), str.end(), res.begin());
        return res;
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
        cout << s.toLowerCase(str).c_str() << endl;
    }
}