#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int size = A.size();
        
        vector<int> res(size);
        if (size == 0)
            return res;

        //locate the absolute smalest element
        int minIndex = 0;
        int minValue = abs(A[minIndex]);
        
        for (int i = 1; i < size; i++) {
            if (abs(A[i]) < minValue) {
                minValue = abs(A[i]);
                minIndex = i;
            }
        }

        int resPos = 0;
        res[resPos] = minValue * minValue;
        resPos++;

        int negIndex = minIndex - 1;
        int posIndex = minIndex + 1;

        while (negIndex >= 0 && posIndex < size) {
            if (abs(A[negIndex]) <= abs(A[posIndex])) {
                res[resPos++] = A[negIndex] * A[negIndex];
                negIndex--;
            } else {
                res[resPos++] = A[posIndex] * A[posIndex];
                posIndex++;
            }
        }
        while (negIndex >= 0) {
            res[resPos++] = A[negIndex] * A[negIndex];
            negIndex--;
        }
        while (posIndex < size) {
            res[resPos++] = A[posIndex] * A[posIndex];
            posIndex++;
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

        int n = 0;
        cin >> n;

        vector<int> a(n);
        readVector(cin, a, n);

        Solution s;
        vector<int> res = s.sortedSquares(a);
        printVector<int>(cout, res);
        cout << endl;
    }
}