#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long long n, m;
    
    cin >> n >> m;

    if (n <= m)
        cout << 2 * n - 2;
    else
        cout << 2 * m - 1;
}