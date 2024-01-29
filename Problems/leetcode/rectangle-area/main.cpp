#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

    int getRangeIntersect(int x1, int x2, int x3, int x4) {
        long x1i = min(x2, x4);
        long x2i = max(x1, x3);
        if (x1i < x2i)
            return 0;
        else
            return x1i - x2i;
    }

    int area(int A, int B, int C, int D) {
        return (C - A) * (D - B);
    }

public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const int intersectX = getRangeIntersect(A, C, E, G);
        const int intersectY = getRangeIntersect(B, D, F, H);
        const int intersectArea = intersectX * intersectY;

        return (area(A, B, C, D) - intersectArea) + area(E, F, G, H);
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

        vector<int> r(8);
        for (int v = 0; v < 8; v++)
            cin >> r[v];

        Solution s;
        cout << s.computeArea(r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7]) << endl;
    }
}
