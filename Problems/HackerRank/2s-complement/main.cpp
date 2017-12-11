#include <iostream>

using namespace std;

union IntByte
{
    signed int asInt;
    unsigned char asByte[4];
};

int onesFF[256];
int noOfSetBits(int a)
{
    IntByte val;
    val.asInt = a;

    int res = 0;
    for (int j = 0; j < 4; ++j)
        res += onesFF[val.asByte[j] & 0xFF];

    return res;
}

long long solve(int a)
{
    if (a >= 0) {
        if (a == 0)
            return 0;
        else if ((a % 2) == 0)
            return solve(a - 1) + noOfSetBits(a);
        else
            return ((long long)a + 1) / 2 + 2 * solve(a / 2);
    }
    else
    {
        a++;
        return ((long long)(-a) + 1) * 32 - solve(-a);
    }
}

long long calculateOnes(int a, int b)
{
    long long res = 0;
    
    if (a < 0 && b < 0)
        res = solve(a) - solve(b);
    else if (a < 0 && b > 0)
        res = solve(a) + solve(b);
    else
        res = solve(b) - solve(a);

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif
    int tests;
    cin >> tests;
    
   //generating ones
    for (int i = 0; i <= 255; ++i)
    {
        int res = 0;
        int n = i;
        while (n) {
            res++;
            n &= n - 1;  // Забираем младшую единичку.
        }
        onesFF[i] = res;
    }

    for (int t = 0; t < tests; ++t)
    {
        int a, b;
        cin >> a >> b;

        long long ones = calculateOnes(a, b);

        cout << ones << endl;
    }
}