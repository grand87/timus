#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long long a, b;
    cin >> a >> b;
    const int total = a + b - 1;
    cout << total - a << " " << total - b;
}