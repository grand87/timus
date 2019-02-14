#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_VAL = 100001;

long long arr[MAX_VAL];

/*Complete the function below*/
long long minDist(long long arr[], long long n, long long x, long long y)
{
    map<int, vector<int>> idx;

    for (int j = 0; j < n; j++) {
        if(arr[j] == x || arr[j] == y)
            idx[arr[j]].push_back(j);
    }

    int ans = -1;
    if (idx[x].size() > 0 && idx[y].size() > 0) {
        ans = MAX_VAL;
        for (int i = 0; i < idx[x].size(); i++) {
            for (int j = 0; j < idx[y].size(); j++) {
                const long long diff = abs(idx[x][i] - idx[y][j]);
                if (diff < ans)
                    ans = diff;
            }
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        long long x, y;
        cin >> x >> y;

        cout << minDist(arr, n, x, y) << endl;
    }
    return 0;
}