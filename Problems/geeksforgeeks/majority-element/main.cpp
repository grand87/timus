#include <iostream>
#include <vector>

using namespace std;

long long arr[10000001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        vector<int> freq(1000000);

        const int minReqFreq = n / 2 + 1;

        int majorSoFar = -1;
        int majorSoFarValue = 0;
        for (int j = 0; j < n; j++) {
            ++freq[arr[j]];
            if (freq[arr[j]] > majorSoFarValue) {
                majorSoFarValue = freq[arr[j]];
                majorSoFar = arr[j];
            }
            if (freq[arr[j]] >= minReqFreq) {
                //result
                break;
            } else //check is there an option att all to locate more max
                if (n - j < minReqFreq - majorSoFarValue) {
                    //no possibilty to locate more items in any way
                    break;
                }
        }

        if (majorSoFarValue > n / 2)
            cout << majorSoFar << endl;
        else
            cout << "-1\n";
    }
    return 0;
}