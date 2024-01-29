#include<iostream>
#include<algorithm>

using namespace std;

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

int buf[10000];

int countMaxSum(int* data, int size) {
    int res = 0;
    int dp[10000];

    dp[0] = data[0];
    dp[1] = max(data[0], data[1]);

    for (int i = 2; i < size; i++) {
        dp[i] = max(data[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[size - 1];
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unsigned long n;
        cin >> n;
        readArray(buf, n);
        cout << countMaxSum(buf, n) << endl;
    }
    return 0;
}