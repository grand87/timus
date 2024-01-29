#include <iostream>
#include <map>

using namespace std;

const int cMaxN = 50001 * 3 + 1;
map<int, int> voters;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l[3];
    for (int i = 0; i < 3; ++i) {
        cin >> l[i];
    }

    int maxId = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < l[i]; ++j) {
            int id;
            cin >> id;
            ++voters[id];

            if (id > maxId)
                maxId = id;
        }
    }

    int resCount = 0;
    for (int i = 0; i < maxId; ++i) {
        if (voters[i] > 1)
            ++resCount;
    }
    cout << resCount << endl;
    for (int i = 0; i < maxId; ++i) {
        if (voters[i] > 1)
            cout << i << endl;
    }
}