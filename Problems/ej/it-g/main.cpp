#include<iostream>
#include<algorithm>

using namespace std;

int checkPoints[1000000];

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//#endif
    int checkPointsCount;
    cin >> checkPointsCount;

    for (int i = 0; i < checkPointsCount; i++)
        cin >> checkPoints[i];

    int d[1000] = { 0 };
    for (int i = 0; i < checkPointsCount; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (checkPoints[j] < checkPoints[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    int maxCheckPoints = d[0];
    for (int i = 1; i < checkPointsCount; i++) {
        if (d[i] > maxCheckPoints) {
            maxCheckPoints = d[i];
        }
    }

    cout << maxCheckPoints;

    return 0;
}