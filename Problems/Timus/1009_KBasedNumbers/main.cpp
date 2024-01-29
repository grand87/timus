#include <stdio.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif

    int k, n;
    scanf("%d %d", &n, &k);

    long long dp[20];
    dp[0] = k - 1;
    dp[1] = k * dp[0];

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
    }

    printf("%lld", dp[n - 1]);

    return 0;
}