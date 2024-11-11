#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif

    long long s;
    scanf("%lld", &s);

    int c = 0;
    long long ps = 0;
    while (s - ps > 0) {
        c++;
        s -= ps;
        if (s == 1) {
            break;
        }
        int a = (int)sqrt(s);
        ps = a * a;
    }

    printf("%d", c);

    return 0;
}