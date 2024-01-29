#include <iostream>

using namespace std;

const int cMaxN = 100001;
int stacks[cMaxN] = { 0 };

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int maxH;
    cin >> n >> maxH;

    for (int i = 0; i < n; ++i)
        cin >> stacks[i];

    int cmd = 0;
    bool empty = true;
    int pos = 0;

    while (true) {
        cin >> cmd;
        if (cmd == 0)
            break;

        switch (cmd) {
        case 1:
            if (pos > 0)
                --pos;
            break;
        case 2:
            if (pos < n - 1)
                ++pos;
            break;
        case 3:
            if (empty && stacks[pos] > 0) {
                empty = false;
                --stacks[pos];
            }
            break;
        case 4:
            if (!empty && stacks[pos] < maxH) {
                empty = true;
                ++stacks[pos];
            }
            break;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << stacks[i] << " ";
}