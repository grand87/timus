#include<iostream>
using namespace std;

int digitSum(int value) {
    int sum = 0;

    while (value != 0) {
        sum += value % 10;
        value /= 10;
    }

    return sum;
}

int reverse(int val) {
    int result = 0;
    while (val != 0) {
        result = result * 10 + val % 10;
        val /= 10;
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        const int sum = digitSum(n);
        const int revSum = reverse(sum);

        if (sum == revSum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}