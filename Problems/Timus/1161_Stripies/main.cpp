#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin >> n;

    vector<int> stripes(n);
    for (int i = 0; i < n; ++i)
        cin >> stripes[i];
    sort(stripes.begin(), stripes.end(), greater<int>());

    double r = stripes[0];
    for (int i = 1; i < n; ++i)
    {
        r = sqrt(r * stripes[i]) * 2;
    }

    printf("%.2f", r);
}