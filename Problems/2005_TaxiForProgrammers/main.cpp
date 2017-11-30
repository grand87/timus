#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif

    const int MAX_P = 5;
    int distances[MAX_P][MAX_P];

    for (int i = 0; i < MAX_P; ++i)
        for (int j = 0; j < MAX_P; ++j)
            cin >> distances[i][j];

    
    long shortestPath = MAX_P * 10000;
    int shortestRoute = -1;

    //generation permutations & evalutaion the path - if shortest - store to the seq

    //due to small amount of input data - hard code the possible routes
    const int routes[][MAX_P] = {
        { 1, 2, 3, 4, 5 },
        { 1, 3, 2, 4, 5 },
        { 1, 3, 4, 2, 5 },
        { 1, 4, 3, 2, 5 },
    };

    for (int p = 0; p < 4; ++p)
    {
        int dist = 0;
        for (int t = 1; t < MAX_P; ++t)
        {
            const int fromP = routes[p][t - 1] - 1;
            const int toP = routes[p][t] - 1;

            dist += distances[fromP][toP];
        }
        if (dist < shortestPath)
        {
            shortestPath = dist;
            shortestRoute = p;
        }
    }

    cout << shortestPath << endl;
    for (int i = 0; i < MAX_P; ++i)
    {
        cout << routes[shortestRoute][i] << " ";
    }
}