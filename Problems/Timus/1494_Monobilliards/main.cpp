#include <iostream>

using namespace std;

const int MAX_N = 100000;

int buffer[MAX_N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin >> n;

    int pos = 0;
    int balls = 0;
    int maxBall = 0;

    for (int i = 0; i < n; ++i)
    {
        int b;
        cin >> b;

        if (b == buffer[pos - 1] && pos > 0)
        {
            --pos;
        }
        else if (b > maxBall)
        {
            for (int i = maxBall + 1; i < b; ++i)
                buffer[pos++] = i;
            maxBall = b;
        }
        else
        {
            break;
        }
    }
    if (pos == 0)
    {
        cout << "Not a proof" << endl;
    }
    else
    {
        cout << "Cheater" << endl;
    }
}