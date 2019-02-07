#include<iostream>
using namespace std;

int loopIDs[1000000] = { 0 };
int a[1000000];

int locateStartPos(int prevStart, int* array, int *ids, int size) {
    // need to locate first untouched pos
    for (int k = prevStart; k < size; k++) {
        if (ids[k] == 0 && array[k] >= 0 && array[k] < size) {
            return k;
        }
    }
    return size;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> a[j];
            loopIDs[j] = 0;
        }

        bool loopDetected = false;
        int loopID = 1;
        int pos = locateStartPos(0, a, loopIDs, n);
        int lastStartPos = 0;

        while (!loopDetected) {
            if (loopIDs[pos] != 0) {
                if (loopIDs[pos] == loopID) {
                    loopDetected = true;
                    break;
                } else {
                    // need to locate first untouched pos
                    pos = locateStartPos(lastStartPos + 1, a, loopIDs, n);
                    if (pos == n) //no more from where to go - terminating
                        break;
                    lastStartPos = pos;
                    loopID++;
                    continue;
                }
            }

            if (a[pos] < 0) {
                // need to locate first untouched pos
                pos = locateStartPos(lastStartPos + 1, a, loopIDs, n);
                if (pos == n) //no more from where to go - terminating
                    break;
                lastStartPos = pos;
                loopID++;
                continue;
            }

            loopIDs[pos] = loopID;
            if (a[pos] != pos && a[pos] < n) {
                pos = a[pos];
            } else {
                //is self loop located or out of range index located
                //not consider self loop as loop - need to locate first untouched pos
                pos = locateStartPos(lastStartPos + 1, a, loopIDs, n);
                if (pos == n) //no more from where to go - terminating
                    break;
                lastStartPos = pos;
                loopID++;
                continue;
            }
        }

        if (loopDetected)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}