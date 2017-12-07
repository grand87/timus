#include <iostream>

using namespace std;

const long MAX_POINTS = 1000;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    long n;
    long distances[MAX_POINTS];

    double totalDistance = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> distances[i];
        totalDistance += distances[i];
    }

    /* to determine minimal distance from some point to all other we need to solve below expression
     * min f(x) = ((a1 - x)^2 + (a2 - x)^2 + (a3 - x)^2 + ... + (aN - x)^2) / N
     * due to we need to minimize it - we can use derivative from function f(x) - f(x)': 
     * f(x)' = (a1^2 - 2a1x + x2 + ... + aN^2 - 2aNx + x^2)/N,
     *       = (2a1 + ... 2aN + 2Nx - x(a1 + ... aN))/N
     *       = (2x - (2/N)(a1 + ... + aN))
     *       => x = (a1 + ... aN) / 2
     * (refer to https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8#Правила_дифференцирования)
     *
     *
     */

    cout.setf(std::ios::fixed, std::ios::floatfield);
    cout.precision(6);
    cout << totalDistance / n;
}