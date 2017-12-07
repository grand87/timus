#include <iostream>

using namespace std;

const int MAX_P = 100;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    cin >> n;
    n *= 2;

    float r;
    cin >> r;

    //x,y,x,y,....,x,y
    double point[MAX_P * 2];

    int i = 0;
    for (i = 0; i < n; i+=2)
    {
        cin >> point[i] >> point[i + 1];
    }
    point[i] = point[0];
    point[i + 1] = point[1];

    double dist = 0;
    for (int i = 0; i < n; i+=2)
    {
        double xs = (point[i + 2] - point[i]);
        xs *= xs;

        double ys = (point[i + 3] - point[i + 1]);
        ys *= ys;

        dist += sqrt(xs + ys);
    }

    dist += 2 * 3.14159 * r;

    cout.setf(std::ios::fixed, std::ios::floatfield);
    cout.precision(2);
    cout << dist;
}