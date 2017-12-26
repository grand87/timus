#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long long a;

    cin >> a;

    if (a % 2 == 0)
        cout << a / 2;
    else if (a == 1)
        cout << 0;
    else
        cout << a;
}