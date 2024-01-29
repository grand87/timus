#include <iostream>

using namespace std;

const int cMaxObstacles = 101;
int obstacles[cMaxObstacles] = { 0 };

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    cin >> n;

    int exitPos;
    cin >> exitPos;

    // need to locate min possitive & min negative

    int minNegative = -1000;
    int minPositive = +1000;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;

        if (c > 0) {
            if (c < minPositive)
                minPositive = c;
        } else {
            if (c > minNegative)
                minNegative = c;
        }
    }

    // is there an exit
    if (exitPos > minNegative && exitPos < minPositive) {
        if (exitPos < 0)
            cout << abs(exitPos) + 2 * minPositive << " " << abs(exitPos) << endl;
        else
            cout << exitPos << " " << abs(minNegative) * 2 + exitPos << endl;
    }
    else
        cout << "Impossible" << endl;
}