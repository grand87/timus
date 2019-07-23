#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utils.h>

using namespace std;

class Solution {

    unordered_map<int, int> maxPath;

    int findLongestWay(int pairStart, const vector<int>& pairsFirstMembers, const unordered_map<int, vector<int>>& pairs) {
        if (pairs.find(pairStart) == pairs.end())
            return 0;

        if (maxPath.find(pairStart) != maxPath.end()) {
            return maxPath.at(pairStart);
        }

        //get neighbor
        const vector<int> &neighbors = pairs.at(pairStart);
        //locate next possible pair - search all values in pairsFirstMembers which will be bigger then neighbor

        int len = 0;
        vector<int> potentialNextPair;
        for (int fmember : pairsFirstMembers) {
            for (int neighbor : neighbors) {
                if (fmember > neighbor) {
                    potentialNextPair.push_back(fmember);
                }
            }
        }

        for(auto next : potentialNextPair) {
            len = max(len, 1 + findLongestWay(next, pairsFirstMembers, pairs));
        }
        maxPath[pairStart] = len;

        return len;
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //need to form array of first members - used to find next possible pair with binary search

        vector<int> firstMembrs;
        firstMembrs.reserve(pairs.size());
        for (auto p : pairs) {
            firstMembrs.push_back(p[0]);
        }
        sort(firstMembrs.begin(), firstMembrs.end());

        //need to find quickly second member for a given first
        unordered_map<int, vector<int>> orderedPairs;
        for (auto pr : pairs) {
            orderedPairs[pr[0]].push_back(pr[1]);
        }
        int res = 0;

        //bruteforce
        for (auto p : pairs) {
            int w = findLongestWay(p[0], firstMembrs, orderedPairs);
            res = max(w, res);
        }

        return res + 1;
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

        vector<vector<int>>pairs(n);

        for (int j = 0; j < n; j++) {
            pairs[j].resize(2);
            cin >> pairs[j][0];
            cin >> pairs[j][1];
        }

        Solution s;
        cout << s.findLongestChain(pairs) << endl;
    }
}