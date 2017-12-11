#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    map<string, int> strings;

    int s;
    cin >> s;

    char buff[25];
    for (int i = 0; i < s; ++i)
    {
        cin >> buff;
        string a(buff);
        strings[a]++;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> buff;
        string a(buff);
        cout << strings[a] << endl;
    }

    return 0;
}
