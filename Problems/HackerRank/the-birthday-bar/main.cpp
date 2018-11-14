#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector < int > s, int d, int m) {
    vector < int > c;

    if (n == 1 && m == 1 && s[0] == d)
        return 1;
    else
    {
        c.reserve(n + m);
        c.push_back(0);
        for (int i = 0; i < n; ++i)
            c.push_back(c[i] + s[i]);

        int ss = 0;

        for (int i = 0; i <= n - m; ++i)
        {
            const int diff = c[i + m] - c[i];
            cout << diff << " ";
            if (diff == d)
                ++ss;
        }
        return ss;
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    int n;
    cin >> n;
    vector<int> s(n);
    for (int s_i = 0; s_i < n; s_i++) {
        cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << endl << result << endl;
    return 0;
}
