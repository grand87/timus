#include <iostream>

using namespace std;

long long arr[10000001] = {0};

int countBits(int n) {
    int masks[16] = {
        0, //0000
        1, //0001
        1, //0010
        2, //0011
        1, //0100
        2, //0101
        2, //0110
        3, //0111
        1, //1000
        2, //1001
        2, //1010
        3, //1011
        2, //1100
        3, //1101
        3, //1110
        4, //1111
    };
    int count = masks[n & 0xF];
    while (n > 0) {
        n >>= 4;
        count += masks[n & 0xF];
    }
    return count;
}

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        const int diff = n ^ m;
        cout << countBits(diff) << endl;
    }
    return 0;
}