#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int arr[10000];

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
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        long long int prev_max_product = arr[0];
        long long int prev_min_product = arr[0];
        long long int cur_max_product = arr[0];
        long long int cur_min_product = arr[0];

        long long int ans = arr[0];

        for (int j = 1; j < n; j++) {
            const auto a1 = prev_max_product * arr[j];
            const auto a2 = prev_min_product * arr[j];

            cur_max_product = max(a1, max(a2, arr[j]));
            cur_min_product = min(a1, min(a2, arr[j]));

            ans = max(ans, cur_max_product);

            prev_max_product = cur_max_product;
            prev_min_product = cur_min_product;
        }

        cout << ans << endl;
    }

    return 0;
}