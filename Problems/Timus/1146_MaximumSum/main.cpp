#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const int cMaxN = 101;
int matrix[cMaxN][cMaxN];

int subArraySum(int ai, int aj, int ak, int al) {
    int sum = 0;
    for (int i = ai; i <= ak; ++i)
        for (int j = aj; j <= al; ++j)
            sum += matrix[i][j];
    return sum;
}

void dump(int n, int a[cMaxN][cMaxN]) {
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "\t" << a[i][j] << " ";
        }
        cout << endl;
    }
}

int sum(int x1, int y1, int x2, int y2, int a[cMaxN][cMaxN]) {
    if (x2 == 0 && y2 == 0) {
        return a[0][0];
    }

    if (x1 == 0 && y1 == 0) {
        return a[x2][y2];
    }

    return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    }
//#ifndef ONLINE_JUDGE
//    dump(n, matrix);
//#endif
    for (int i = 1; i < n; ++i) {
        matrix[0][i] += matrix[0][i - 1] ;
        matrix[i][0] += matrix[i - 1][0];
    }

    for (int j = 1; j < n; ++j)
        for (int i = 1; i < n; ++i) {
            matrix[j][i] += matrix[j][i - 1] + matrix[j - 1][i] - matrix[j - 1][i - 1];
        }
//#ifndef ONLINE_JUDGE
//    dump(n, matrix);
//    cout << sum(0, 0, 0, 0, matrix) << endl;
//    cout << sum(0, 0, 1, 1, matrix) << endl;
//    cout << sum(0, 0, 0, n - 1, matrix) << endl;
//    cout << sum(0, 0, n - 1, 0, matrix) << endl;
//    cout << sum(0, 0, n - 1, n - 1, matrix) << endl;
//    cout << sum(1, 0, 3, 1, matrix) << endl;
//#endif

    int max_sum = matrix[0][0];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = i; k < n; ++k)
                for (int l = j; l < n; ++l)
                {
                    int currentSum = sum(j, i, l, k, matrix);
                    if (currentSum > max_sum) {
                        max_sum = currentSum;
                    }
                }

    cout << max_sum <<endl;
    return 0;
}  