#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

    void reverse(string &s, int start, int size) {
        for (int i = 0; i < size / 2; i++) {
            swap(s[start + i], s[start + size - i - 1]);
        }
    }

public:
    string reverseStr(string s, int k) {
        int processed = 0;
        const int size = s.length();
        while (processed < size) {
            const int chunkSize = min(size - processed, k);
            if (chunkSize == 1)
                break;
            reverse(s, processed, chunkSize);
            processed += 2 * k;
        }
        return s;
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

        char buf[10001];
        cin >> buf;
        int k;
        cin >> k;
        Solution s;
        cout << s.reverseStr(string(buf), k).c_str() << endl;
    }
}