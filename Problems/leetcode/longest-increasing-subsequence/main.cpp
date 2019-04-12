#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        int maxLis = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis[i] = max(lis[j] + 1, lis[i]);
                    maxLis = max(lis[i], maxLis);
                }
            }
        }
        return maxLis;
    }
};

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        vector<int> numbers(n);
        if(n > 0)
            readArray(&numbers[0], n);
        int answer;
        cin >> answer;
        Solution s;
        auto res = s.lengthOfLIS(numbers);
        cout << "TEST " << i + 1 << " "<< res << endl;
        assert(answer == res);
    }
}