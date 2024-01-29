#include <iostream>

using namespace std;

long long arr[10000001] = {0};

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y, n;
        cin >> x >> y >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        int jumps = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] <= x)
                jumps++;
            else {
                jumps++;
                int height = x;
                while (height < arr[j]) {
                    height-=y;
                    height += x;
                    jumps++;
                }
            }
        }

        cout << jumps << endl;
    }
    return 0;
}