#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

constexpr double cPi = 3.1415926;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif`
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float a = 0;
    float r = 0;
    cin >> a >> r;

    const float D = sqrt(2) * a;
    const float d = D / 2;

    if (d <= r) {
        cout << setprecision(10);
        cout << setprecision(10) << a * a;
    }
    else if (r <= a / 2) {
        cout << setprecision(10);
        cout << setprecision(10) << cPi * r * r;
    } else {
        double gama = 2 * acos((a/2) / r);
        double sqaureSeg = 0.5 * r * r *(gama - sin(gama));
        double cSquare = cPi * r * r;
        cout << setprecision(10) << cSquare - 4 * sqaureSeg;
    }

    return 0;
}  