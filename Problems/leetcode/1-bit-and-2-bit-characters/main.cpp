#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1 && bits[0] == 1)
            return false;

        bool result = true;
        int pos = 0;
        while (pos < bits.size()) {
            if (bits[pos] == 0) {
                pos++;
                result = true;
                continue;
            }

            if (pos + 1 < bits.size()) {
                pos += 2;
                result = false;
                continue;
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

        int n;
        cin >> n;

        vector<int> bits(n);
        for (int j = 0; j < n; j++) {
            cin >> bits[j];
        }

        Solution s;
        cout << (s.isOneBitCharacter(bits) ? "True" : "False") << endl;
    }
}