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

int buf[1000000];
int lis[1000000];
int sum[1000000];

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

        for (int j = 0; j < n; j++) {
            lis[j] = 1;
            counts[j] = 0;
            sum[j] = buf[j];
        }

        sum[0] = buf[0];
        int maxSum = sum[0];

        int j = 0;
        for (int j = 1; j < n; j++) {

            for (int k = 0; k < j; k++) {
                if (buf[k] < buf[j]) {
                    lis[j] = max(lis[k] + 1, lis[j]);
                    sum[j] = max(sum[k] + buf[j], sum[j]);
                    maxSum = max(sum[j], maxSum);
                }
            }
        }

        cout << maxSum << endl;
    }
    return 0;
}