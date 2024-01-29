#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int size = nums.size();

        if (size == 0)
            return 0;

        vector<int> lis(size, 1);
        vector<int> incl(size, 1);
        int maxLIC = 1;
        int result = 1;
        
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lis[i] == lis[j] + 1) {
                        incl[i] += incl[j];
                    }
                    if (lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        incl[i] = incl[j];
                    }
                }
            }

            if (maxLIC == lis[i]) {
                result += incl[i];
            }

            if (maxLIC < lis[i]) {
                maxLIC = lis[i];
                result = incl[i];
            }
        }
        return result;
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
        auto res = s.findNumberOfLIS(numbers);
        cout << "TEST " << i + 1 << " "<< res << endl;
        assert(answer == res);
    }
}