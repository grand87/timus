#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int historgrams[2][26] = { {0},{0} };
        for (int i = 0; i < s.size(); i++)
            historgrams[0][s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++)
            historgrams[1][t[i] - 'a']++;

        //compare 2 histograms
        for (int i = 0; i < 26; i++) {
            if (historgrams[0][i] != historgrams[1][i])
                return 'a' + i;
        }
        return 0;
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

        char buf1[10000];
        char buf2[10000];

        cin >> buf1 >> buf2;

        Solution s;
        cout << s.findTheDifference(string(buf1), string(buf2)) << endl;
    }
}