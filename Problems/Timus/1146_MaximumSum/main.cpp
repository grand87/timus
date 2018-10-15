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


    for (int i = 1; i < n; ++i) {
        matrix[0][i] += matrix[0][i - 1];
        matrix[i][0] += matrix[i - 1][0];
    }

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            matrix[i][j] += matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1];


    int temp = 0;
    int max_sum = matrix[0][0];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = i; k < n; ++k)
                for (int l = 0; l < j; ++l) {
                    temp = matrix[k][j];
                    if (i > 0 && l > 0)
                        temp += matrix[i - 1][l - 1];

                    if (i > 0)
                        temp -= matrix[i - 1][j];

                    if (l > 0)
                        temp -= matrix[k][l - 1];

                    if (temp > max_sum)
                        max_sum = temp;
                }


    cout << max_sum;
    return 0;
}  