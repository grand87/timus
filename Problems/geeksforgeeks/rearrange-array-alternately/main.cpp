#include <fstream>
#include <vector>
#include <iostream>
#include <utils.h>

using namespace std;

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 1; i < n; i+=2) {
            cin >> arr[i];
        }

        for (int i = n - 2 + (n % 2); i >= 0; i-=2) {
            cin >> arr[i];
        }

        printVector(cout, arr);
        cout << endl;

    }
    return 0;
}