#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long long n, k;
    
    cin >> n >> k;

    if (n <= k)
        cout << 2;
    else
        cout << ceil(n * 2.f / k);
}