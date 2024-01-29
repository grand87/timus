#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {

public:
    int maxLength(vector<string>& arr) {
        if (arr.size() == 1)
            return arr[0].size();

        vector<unsigned int> lettersMask(arr.size());
        for (int si = 0; si < arr.size(); si++) {
            unsigned int mask = 0;
            for (char c : arr[si]) {
                const int symbolCode = c - 'a';
                mask |= (1 << symbolCode);
            }
            lettersMask[si] = mask;
        }

        unsigned int maxLen = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxLen = max(arr[i].size(), maxLen);
        }

        //for (int i = 0; i < arr.size() - 1; i++) {
        //    for (int j = i + 1; j < arr.size(); j++) {
        //        const unsigned int common = lettersMask[i] & lettersMask[j];
        //        if (common == 0) {
        //            // means no common symbols
        //            maxLen = max(maxLen, static_cast<unsigned int>(arr[i].size() + arr[j].size()));
        //        }
        //    }
        //}

        vector<int> dp(arr.size());

        unsigned int currentMax = arr[0].size();


        for (int i = 1; i < arr.size(); i++) {
            //what is bigger - current max + new string or new string
        
        }
        return maxLen;
    }
};

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int count;
        cin >> count;

        vector<string> strs(count);
        readVector(cin, strs, count);

        Solution s;
        cout << s.maxLength(strs) << endl;
    }
}