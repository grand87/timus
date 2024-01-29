#include <iostream>
#include <fstream>
#include <algorithm>
#include <utils.h>

using namespace std;

int solution(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    unsigned int count = 0;

    for (int i = arr.size() - 1; i > 1; i--) {
        int l = 0;
        int r = i - 1;

        while (l < r) {
            const int s = arr[l] + arr[r];
            if (s == arr[i]) {
                count++;
                l++;
                r--;
            }
            else if (s < arr[i]) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    if (count == 0)
        count = -1;
    return count;
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