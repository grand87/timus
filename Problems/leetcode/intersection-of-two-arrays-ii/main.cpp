#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <utils.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> uniqueFreq;
        unordered_map<int, int> uniqueFreq2;

        for (int v : nums1)
            uniqueFreq[v]++; // log(n) complexity

        for (int v : nums2)
            uniqueFreq2[v]++; // log(n) complexity

        set<int> common;

        for (auto u : uniqueFreq) {
            auto uf2It = uniqueFreq2.find(u.first); // log(n) complexity
            if (uf2It != uniqueFreq2.end()) {
                uniqueFreq[u.first] = min(u.second, uf2It->second);
                common.insert(u.first); // log(n) complexity
            }
        }

        vector<int> res;
        for (int v : common) {
            const int count = uniqueFreq[v];
            for (int i = 0; i < count; i++)
                res.push_back(v);
        }

        return res;
    }
};

int main()
{
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int v1, v2;
        cin >> v1 >> v2;
        vector<int> values1(v1);
        readVector<int>(cin, values1, v1);

        vector<int> values2(v2);
        readVector<int>(cin, values2, v2);


        Solution s;
        values1 = s.intersect(values1, values2);
        printVector<int>(cout, values1);

        cout << endl;
    }
    return 0;
}
