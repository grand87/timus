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

class KthLargest {

    priority_queue <int, vector<int>, greater<int> > pq;
    int kpos;

public:
    KthLargest(int k, vector<int>& nums) {
        kpos = k;
        for (int v : nums)
            add(v);
    }

    int add(int val) {
        if (pq.size() < kpos) {
            pq.push(val);
        } else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> buf(n);
        readVector(cin, buf, n);
        vector<int> addBuf(m);
        readVector(cin, addBuf, m);
        KthLargest s(k, buf);

        for (int j = 0; j < m; j++) {
            cout << s.add(addBuf[j]) << endl;
        }
    }
}