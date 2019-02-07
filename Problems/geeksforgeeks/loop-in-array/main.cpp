#include<iostream>
using namespace std;

int loopIDs[1000000] = { 0 };
int a[1000000];

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
        int pos = 0;
        int lastStartPos = 0;

        // need to locate first untouched pos
        for (int k = pos; k < n; k++) {
            if (loopIDs[k] == 0 && a[k] >= 0) {
                pos = k;
                lastStartPos = k;
                break;
            }
        }

        while (!loopDetected) {
            if (loopIDs[pos] != 0) {
                if (loopIDs[pos] == loopID) {
                    loopDetected = true;
                    break;
                } else {
                    //we located path evaluated before - need to search new path
                    int oldLoopID = loopID;
                    // need to locate first untouched pos
                    for (int k = lastStartPos + 1; k < n; k++) {
                        if (loopIDs[k] == 0 && a[k] > 0) {
                            pos = k;
                            lastStartPos = k;
                            //start to search new loop
                            loopID++;
                            break;
                        }
                    }
                    if (loopID == oldLoopID)
                        //no more from where to go - terminating
                        break;
                }
            }

            if (a[pos] < 0) {
                int oldLoopID = loopID;
                // need to locate first untouched pos
                for (int k = lastStartPos + 1; k < n; k++) {
                    if (loopIDs[k] == 0 && a[k] >= 0) {
                        pos = k;
                        lastStartPos = k;
                        //start to search new loop
                        loopID++;
                        break;
                    }
                }
                if(loopID == oldLoopID)
                    //no more from where to go - terminating
                    break;
            }

            loopIDs[pos] = loopID;
            if(a[pos] != pos) //is self loop located
                pos = a[pos];
            else {
                //not consider self loop as loop

                int oldLoopID = loopID;
                // need to locate first untouched pos
                for (int k = lastStartPos + 1; k < n; k++) {
                    if (loopIDs[k] == 0 && a[k] >= 0) {
                        pos = k;
                        lastStartPos = k;
                        //start to search new loop
                        loopID++;
                        break;
                    }
                }
                if (loopID == oldLoopID)
                    //no more from where to go - terminating
                    break;
            }
        }

        if (loopDetected)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}