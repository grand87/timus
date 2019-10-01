#include <algorithm>
#include <iostream>
#include <fstream>
#include <utils.h>

using namespace std;

int solution(const vector<int> & arr) {
    
    int minValue = arr[0];
    int diff = 0;

    for (int i = 1; i < arr.size(); i++) {
        diff = max(diff, arr[i] - minValue);
        minValue = min(minValue, arr[i]);
    }

    if (diff == 0)
        diff = -1;
    return diff;
}

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unsigned int n;
        cin >> n;
        
        vector<int> arr(n);
        readVector(cin, arr, n);

        cout << solution(arr) << endl;
    }
    return 0;
}