#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bonAppetit(int n, int k, int b, vector <int> ar) {
    //calculate the sum which should be splited

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += ar[i] * (i != k);
    }
    if (sum / 2 == b)
        return 0;
    else
        return b - sum / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int ar_i = 0; ar_i < n; ar_i++) {
        cin >> ar[ar_i];
    }
    int b;
    cin >> b;
    int result = bonAppetit(n, k, b, ar);
    if(result == 0)
        cout << "Bon Appetit" << endl;
    else
        cout << result << endl;
    return 0;
}