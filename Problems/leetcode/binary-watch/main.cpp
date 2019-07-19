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

    vector<vector<int>> generateCombinations(int max) {
        constexpr int countsper4Bits[] = {
            0,  //0000 - 0
            1,  //0001 - 1
            1,  //0010 - 2
            2,  //0011 - 3
            1,  //0100 - 4
            2,  //0101 - 5
            2,  //0110 - 6
            3,  //0111 - 7
            1,  //1000 - 8
            2,  //1001 - 9
            2,  //1010 - 10
            3,  //1011 - 11
            2,  //1100 - 12
            3,  //1101 - 13
            3,  //1110 - 14
            4,  //1111 - 15
        };

        vector<vector<int>> res(6);
        
        for (int i = 0; i < max; i++) {
            
            const int q1 = i & 0b1111;
            const int q2 = (i >> 4)& 0b1111;
            const int count = countsper4Bits[q1] + countsper4Bits[q2];
            res[count].push_back(i);
        }

        return res;
    }

public:
    vector<string> readBinaryWatch(int num) {
        const vector<vector<int>> hoursCombinations = generateCombinations(12);
        const vector<vector<int>> minutesCombinations = generateCombinations(60);

        vector<string> res;

        for (int i = 0; i <= num; i++) {
            const int bitsForHour = max(i, min(i, 4));
            if (bitsForHour > 4)
                continue;

            const int bitsForMinutes = num - bitsForHour;
            if (bitsForMinutes > 5)
                continue;

            const vector<int> &hours = hoursCombinations[bitsForHour];
            const vector<int> &minutes = minutesCombinations[bitsForMinutes];
            //generate all combinations for hours vs minutes;

            for (int h = 0; h < hours.size(); h++) {
                for (int m = 0; m < minutes.size(); m++) {
                    stringstream ss;
                    ss << hours[h] << ":";
                    if (minutes[m] < 10)
                        ss << "0";
                    ss << minutes[m];
                    res.push_back(ss.str());
                }
            }
        }

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
        int n;
        cin >> n;

        Solution sol;
        vector<string> res = sol.readBinaryWatch(n);
        for (auto s : res) {
            cout << '[' << s << ']';
        }
        cout << endl;
    }
}