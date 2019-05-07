#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

    int getRangeIntersect(int x1, int x2, int x3, int x4) {
        int res = min(x2, x4) - max(x1, x3);
        return res;
    }

public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        const int intersectX = getRangeIntersect(rec1[0], rec1[2], rec2[0], rec2[2]);
        const int intersectY = getRangeIntersect(rec1[1], rec1[3], rec2[1], rec2[3]);

        return intersectX > 0 && intersectY > 0;
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

        vector<int> r[2];
        for (int j = 0; j < 2; j++) {
            r[j].resize(4);
            for (int v = 0; v < 4; v++)
                cin >> r[j][v];
        }

        Solution s;
        cout << s.isRectangleOverlap(r[0], r[1]) << endl;
    }
}