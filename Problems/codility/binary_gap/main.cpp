#include <iostream>
#include <iostream>

using namespace std;

int solution(int N) {
    int arr[32] = {0};
    int length = 0;

    int first1 = -1;
    int last1 = -1;

    for (int i = 0; i < 32; i++) {
        arr[i] = (N >> i) & 1;
        
        if (arr[i] == 1 && first1 == -1)
            first1 = i;

        if (arr[i] == 1)
            last1 = i;
    }

    //count zeros between first1 & last1
    if (first1 == -1)
        return 0;
    if (first1 == last1)
        return 0;

    int maxZeros = 0;
    int secLen = 0;

    for (int i = first1 + 1; i < last1; i++) {
        if (arr[i] == 0) {
            secLen++;
            if (secLen > maxZeros)
                maxZeros = secLen;
        } else {
            secLen = 0;
        }
    }

    return maxZeros;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int a;
    cin >> a;
    cout << solution(a);
}