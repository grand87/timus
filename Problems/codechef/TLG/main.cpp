#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int scores[2][10001];
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> scores[0][i] >> scores[1][i];
    }

    int leadA = true;
    int currentLead = 0;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            scores[0][i] += scores[0][i - 1];
            scores[1][i] += scores[1][i - 1];
        }
        
        int tmp = scores[0][i] - scores[1][i];

        if (abs(tmp) > currentLead) {
            currentLead = abs(tmp);
            leadA = tmp > 0;
        }
    }

    cout << (leadA ? "1 " : "2 ") << currentLead;
}