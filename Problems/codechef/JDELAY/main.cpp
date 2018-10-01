#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif	
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int longSubmissions = 0;
        int submissions = 0;
        cin >> submissions;
        for (int j = 0; j < submissions; ++j) {
            int start, end;
            cin >> start >> end;
            if (end - start > 5)
                ++longSubmissions;
        }
        cout << longSubmissions << endl;
    }
}