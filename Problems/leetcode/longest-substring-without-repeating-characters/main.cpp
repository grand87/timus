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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> currentSet;
        int maxSoFar = 0;

        int start = 0;
        int pos = 0;
        for (auto c : s) {
            auto loc = currentSet.find(c);
            if (loc != currentSet.end() && loc->second > start)
                start = loc->second + 1;
            currentSet[c] = pos;
            maxSoFar = max(maxSoFar, pos - start + 1);
            pos++;
        }

        return maxSoFar;
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
        string str;
        cin >> str;
        Solution s;
        cout << s.lengthOfLongestSubstring(str) << endl;
    }
}