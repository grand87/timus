#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long long a = 0, b = 0, tmp;

    for (int i = 0; i < 4; ++i)
    {
        cin >> tmp;
        a += tmp;
        cin >> tmp;
        b += tmp;
    }

    if (a > b)
        cout << "1";
    else if (a < b)
        cout << "2";
    else
        cout << "DRAW";
}