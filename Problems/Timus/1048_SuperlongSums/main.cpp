#include <iostream>
#include <stdio.h>
using namespace std;

int buffer[1000002][3];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int digits;
    cin >> digits;

    buffer[0][0] = 0;
    buffer[0][1] = 0;
    buffer[0][2] = 0;

    for (int i = 1; i <= digits; ++i)
        scanf("%d %d", &buffer[i][0], &buffer[i][1]);

    for (int i = digits; i > 0; --i)
    {
        const int res = buffer[i][0] + buffer[i][1] + buffer[i][2];
        buffer[i - 1][2] += res / 10;
        buffer[i][2] = res % 10;
    }

    int offset = 1;
    if (buffer[0][2] > 0)
        offset = 0;
    for (int i = offset; i <= digits; ++i)
        cout << buffer[i][2];
    cout << endl;
}