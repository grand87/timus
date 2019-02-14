#include <iostream>

using namespace std;

long long arr[10000000];
int dist[10000000] = { 0 };

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            dist[j] = 0;
        }

        int startPos = 1;

        int maxDist = 0;

        for (int l = 0; l < n - 1; l++) {
            for (int r = l + startPos; r < n; r++) {
                if (arr[r] >= arr[l]) {
                    if (r - l > dist[r]) {
                        dist[r] = r - l;
                        startPos = dist[r];
                        if (dist[r] > maxDist)
                            maxDist = dist[r];
                    }
                }
            }
        }
        
        cout << maxDist << endl;
    }
    return 0;
}