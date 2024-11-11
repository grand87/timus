/*
 * @author v.sharaienko (grandamx@gmail.com)
 */

#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <string>


using namespace std;

//#define ONLINE_JUDGE

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int wheelSize = 0;
    int ticksCount = 0;
    
    cin >> wheelSize >> ticksCount;

    string wheelContent;

    for (int i = 0; i < wheelSize; i++) {
        string digits;
        cin >> digits;

        wheelContent += digits;
    }

    // remove full rotations
    ticksCount %= wheelSize;

    int pos = ticksCount;
    
    for (int i = 0; i < 10; i++) {
        if (pos >= wheelContent.size()) {
            pos = 0;
        }
        cout << wheelContent[pos];
        pos++;
    }

    return 0;
}
 