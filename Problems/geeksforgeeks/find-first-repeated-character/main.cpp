#include <iostream>
#include <vector>
#include <map>

using namespace std;

char buffer[100000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> countApp(255);

        cin >> buffer;
        bool duplicate = false;
        for (int j = 0; buffer[j] != 0; j++) {
            if (countApp[buffer[j]] == 0) {
                countApp[buffer[j]]++;
            }
            else {
                //this is the repeating character
                cout << buffer[j] << endl;
                duplicate = true;
                break;
            }
        }
        if (!duplicate)
            cout << -1 << endl;
    }
    return 0;
}