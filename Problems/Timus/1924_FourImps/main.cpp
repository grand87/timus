#include <iostream>

using namespace std;

const char* sValues[2] = { "black", "grimy" };

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long n;
    cin >> n;

    long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += i;
    }

    cout << sValues[sum % 2];
}