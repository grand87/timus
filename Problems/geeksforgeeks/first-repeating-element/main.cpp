#include <iostream>
#include <map>

using namespace std;

const int MAX_VAL = 1000100;
int countApp[MAX_VAL + 1];
int arr[MAX_VAL + 1];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        map<int, int> positions;


        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if (positions.find(arr[j]) == positions.end()) {
                positions[arr[j]] = j;
                countApp[arr[j]] = 1;
            }
            else
                countApp[arr[j]]++;
        }

        int lowestPos = n;
        for (int j = 0; j < n; j++) {
            if (countApp[arr[j]] > 1) {
                //it means value `originalValue` appeared more then 2 times starting at position
                if (positions[arr[j]] < lowestPos)
                    lowestPos = positions[arr[j]];
            }
        }

/*
        int j = 0;
        for (; j < n; j++) {
            const int originalValue = arr[j] % MAX_VAL;
            if (arr[originalValue] >= MAX_VAL) {
                countApp[originalValue]++;
            } else {
                pos[originalValue] = j;
                countApp[originalValue] = 1;
                arr[originalValue] += MAX_VAL;
            }
        }
        // need to find element which has 2 or more in the pos with lowest index
        int lowestPos = n;
        for (j = 0; j < n; j++) {
            const int originalValue = arr[j] % MAX_VAL;
            if (countApp[originalValue] >= 2) {
                //it means value `originalValue` appeared more then 2 times starting at position
                if (pos[originalValue] < lowestPos)
                    lowestPos = pos[originalValue];
            }
        }
        */
        if (lowestPos == n) {
            cout << -1 << endl;
        }
        else
            cout << lowestPos + 1 << endl;
    }
    return 0;
}