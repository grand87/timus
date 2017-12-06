#include <iostream>
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

double getPhi(int x, int y)
{
    if (x > 0 && y >= 0)
    {
        const float xy = y / x;
        return atan(xy);
    }
    else if (x > 0 && y < 0)
    {
        const float xy = y / x;
        return atan(xy) + 2 * M_PI;
    }
    else if (x < 0)
    {
        const float xy = y / x;
        return atan(xy) + M_PI;
    }
    else if (x == 0 && y > 0)
    {
        return M_PI_2;
    }
    else if (x == 0 && y < 0)
    {
        return 3 * M_PI / 2.0;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif
    int radius;
    cin >> radius;

    int v1x, v1y, v2x, v2y;
    cin >> v1x >> v1y >> v2x >> v2y;

    int points;
    cin >> points;

    const double s_right = getPhi(v1x, v1y);
    const double s_left = getPhi(v2x, v2y);

    for (int i = 0; i < points; ++i)
    {
        int tx, ty;
        cin >> tx >> ty;

        //determine distance to target
        double tDistance = sqrt(tx * tx + ty * ty);
        bool killed = false;
        if (tDistance <= radius)
        {
            //need to determine is located in the sector
            double tf = getPhi(tx, ty);

            if (s_left >= s_right)
                killed = tf <= s_left && tf >= s_right;
            else
                killed = tf <= s_left || tf > s_right;
        }
        cout << (killed ? "YES\n" : "NO\n");
    }
}