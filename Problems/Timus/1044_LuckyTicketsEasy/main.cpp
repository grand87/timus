/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 9;
const int MAX_K = MAX_N * 9;

int cache[MAX_N][MAX_K];

long getCount(int length = 3)
{
    const int k = length * 9;

    for (int n = 1; n <= length; ++n)
    {
        for (int l = 0; l < k; ++l)
        {
            if (n == 1)
                cache[n][l] = l <= 9 ? 1 : 0;
            else
            {
                long sum = 0;
                for (int g = 0; g <= min(l, 9); ++g)
                    sum += cache[n - 1][l - g];
                cache[n][l] = sum;
            }
        }
    }

    const long res = cache[length][k / 2];
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    size_t value = 0;
    cin >> value;


    cout << getCount(value);
   
    return 0;
}
