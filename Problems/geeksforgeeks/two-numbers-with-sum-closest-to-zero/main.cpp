#include<iostream>
#include<algorithm>

using namespace std;

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

int buf[1000];

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        readArray(buf, n);
        sort(buf, buf + n);
        int l = 0, r = n - 1;
        int sum = buf[l] + buf[r];
        while (l < r) {
            int local_sum = buf[l] + buf[r];
            if (abs(local_sum) < abs(sum)) {
                sum = local_sum;
            }
            if (local_sum < 0)
                l++;
            else if (local_sum > 0)
                r--;
        }
        cout << sum << endl;
    }
    return 0;
}
