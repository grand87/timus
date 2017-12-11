#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    int n, q;
    cin >> n >> q;

    vector< vector<int> > arr(n);
    int lastAnswer = 0;
    for (int i = 0; i < q; ++i)
    {
        int q, x, y;
        cin >> q >> x >> y;
        int index = (x ^ lastAnswer) % n;

        if (q == 1)
        {
            arr[index].push_back(y);
        }
        else
        {
            int subIndex = y % arr[index].size();
            lastAnswer = arr[index][subIndex];
            cout << lastAnswer << endl;
        }
    }

    return 0;
}
