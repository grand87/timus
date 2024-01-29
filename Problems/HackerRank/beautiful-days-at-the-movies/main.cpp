#include <iostream>
#include <vector>

using namespace std;

bool calculated[1000000] = { false };
int values[1000000] = { -1 };

int reverse(int value) {
    int result = 0;
    while (value) {
        int v = value % 10;
        result = result * 10 + v;
        value /= 10;
    }
    return result;
}

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    int count = 0;
    for (int v = i; v <= j; v++) {
        if ((v - reverse(v)) % k == 0)
            count++;
    }
    return count;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int l,r,k;
    cin >> l >> r >> k;
    cout << beautifulDays(l, r, k);
    return 0;
}
