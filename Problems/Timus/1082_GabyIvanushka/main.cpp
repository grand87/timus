#include <iostream>

using namespace std;

const unsigned int MAX_N = 1001;

unsigned int N = 0;
long c;
long A[MAX_N];

long P(long l, long r)
{
    long x = A[l],
        i = l - 1,
        j = r + 1,
        t;
    while (1)
    {
        do { --j; ++c; } while (A[j]>x);
        do { ++i; ++c; } while (A[i]<x);
        if (i<j)
        {
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
        else return j;
    }
}

void Q(long l, long r)
{
    long n;
    if (l < r)
    {
        n = P(l, r);
        Q(l, n);
        Q(n + 1, r);
    }
}

bool check()
{
    c = 0;
    Q(0, N - 1);
    if (c == (N*N + 3 * N - 4) / 2)
        return true;
    else
        return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    
    cin >> N;

    A[0] = 1;

    for (int i = 1; i < N; ++i)
        A[i] = A[i - 1] + 2;

#ifndef ONLINE_JUDGE
    bool a = check();
#endif
    for (int i = 0; i < N; ++i)
    {
        cout << A[i] << " ";
    }
}