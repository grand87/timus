#include <iostream>
#include <map>
#include <algorithm>

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

        map<int,int> freq;

        for (int j = 0; j < n; j++) {
            ++freq[arr[j]];
        }

        //find the max in array or return -1 if all equals;

        int maxFreq = 0;
        int maxFreqValue = 0;
        int prevFreq = 0;
        bool allEqual = true;
        bool firstValue = true;

        for (map<int,int>::iterator it = freq.begin(); it != freq.end(); it++) {
            if (it->second > n/2) {
                maxFreqValue = it->first;
                maxFreq = maxFreqValue;
                allEqual = false;
                break;
            }
        }

        if (allEqual)
            cout << "-1\n";
        else
            cout << maxFreqValue << endl;
    }
    return 0;
}