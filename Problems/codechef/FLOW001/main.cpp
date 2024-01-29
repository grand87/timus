#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int tc = 0; tc < n; ++tc) {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
}