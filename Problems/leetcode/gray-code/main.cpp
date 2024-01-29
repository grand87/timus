#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

public:
    vector<int> grayCode(int n) {
        vector<int> res(1);
        res[0] = 0;

        for(int i = 0; i < n; i++) {
            const int size = res.size();
            for (int j = 0; j < size; j++) {
                res.push_back(res[size - j - 1] | 1 << i);
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

        Solution s;
        vector<int> result = s.grayCode(n);
        for (int j = 0; j < result.size(); j++) {
            cout << result[j] << " ";
        }
      
        cout << endl;
    }
}