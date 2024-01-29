#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

int tmpdata[100][100];

int lcaDP(const string& s1, const string& s2, int a, int b) {

    if (s1.compare(s2) == 0)
        tmpdata[a][b] = s1.size();

    for(int i = 0; i <= a + 1; i++)
        for (int j = 0; j <= b + 1; j++) {
            if (i == 0 || j == 0)
                tmpdata[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) {
                assert(tmpdata[i - 1][j - 1] != -1);
                tmpdata[i][j] = 1 + tmpdata[i - 1][j - 1];
            } else {
                assert(tmpdata[i][j - 1] != -1);
                assert(tmpdata[i - 1][j] != -1);
                tmpdata[i][j] = max(tmpdata[i - 1][j], tmpdata[i][j - 1]);
            }
        }

    return tmpdata[a][b];
}

int lca(const string& s1, const string& s2, int a, int b) {
    if (a == 0 || b == 0)
        return 0;

    if (s1.compare(s2) == 0)
        return s1.size();

    if (s1[a - 1] == s2[b - 1])
        return 1 + lca(s1, s2, a - 1, b - 1);

    return max(lca(s1, s2, a - 1, b), lca(s1, s2, a, b - 1));
}

void resetData(int a, int b) {
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            tmpdata[i][j] = -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        string sa, sb;
        cin >> sa >> sb;

        resetData(a, b);
        cout << lcaDP(sa, sb, a, b) << endl;
    }
    return 0;
}