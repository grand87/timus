#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

int arr[150];

using namespace std;

bool sortbyfreq(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        //map will sort by key value
        map<int, int> freq;
        for (int j = 0; j < n; j++) {
            freq[arr[j]]++;
        }

        //sort by freq
        vector< pair<int, int> > freqValues(freq.begin(), freq.end());
        sort(freqValues.begin(), freqValues.end(), sortbyfreq);
        
        for (vector< pair<int, int> >::iterator it = freqValues.begin(); it != freqValues.end(); it++) {
            for (int j = 0; j < it->second; j++) {
                cout << it->first << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
