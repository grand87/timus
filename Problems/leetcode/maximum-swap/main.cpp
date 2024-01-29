#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // locate smallest from the front

        int vLen = 0;
        int val[10];

        int tmp = num;
        while (tmp) {
            val[vLen++] = tmp % 10;
            tmp /= 10;
        }

        int l = 0;
        int r = vLen - 1;
        while (l < r) {
            swap(val[l], val[r]);
            ++l;
            --r;
        }

        // search max from the left;
        int biggestIndexStart = 0;
        int i = 0;
        for (; i < vLen; i++) {
            biggestIndexStart = i;
            int biggestIndex = i;
            int biggest = val[biggestIndexStart];

            for (int j = i + 1; j < vLen; j++) {
                if (val[j] >= biggest) {
                    biggest = val[j];
                    biggestIndex = j;
                }
            }

            if (biggestIndexStart != biggestIndex && val[biggestIndex] != val[biggestIndexStart]) {
                biggestIndexStart = biggestIndex;
                break;
            }
            i = biggestIndex;
        }

        if (i == vLen) {
            // no way
            return num;
        }

        // search the first smaller element in front of it
        for (int i = 0; i < biggestIndexStart; i++) {
            if (val[i] < val[biggestIndexStart]) {
                swap(val[i], val[biggestIndexStart]);
                break;
            }
        }

        int result = 0;
        for (int i = 0; i < vLen; i++) {
            result *= 10;
            result += val[i];
        }

        return result;
    }
};

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int b;
        cin >> b;

        Solution s;
        cout << s.maximumSwap(b) << endl;
    }
}