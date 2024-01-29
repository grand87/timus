#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() < n / 2)
            false;

        int count = 0; // represents free spots
        for (int i = 0; i < flowerbed.size();) {
            if (flowerbed[i] == 0) {
                if (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0) {
                    // i can put pot here
                    count++;
                    i += 2;
                }
                else {
                    // i can not put pot here - but next possible place to put a pot is i + 3
                    // Example
                    //          0 1 0 0
                    //          ^     ^
                    //
                    i += 3;
                }
            }
            else {
                // i can not put pot here - but next possible place to put a pot is i + 2
                i += 2;
            }
        }

        return count >= n;
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

        int n = 0, m = 0;
        cin >> n >> m;

        vector<int> flowerbed(n);
        for (int j = 0; j < n; j++) {
            cin >> flowerbed[j];
        }

        Solution s;
        cout << s.canPlaceFlowers(flowerbed, m) << endl;
    }
}