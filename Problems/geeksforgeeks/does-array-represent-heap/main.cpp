#include <iostream>

using namespace std;

long long arr[10000001] = {0};

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return i * 2 + 2;
}

bool isHeap_helper(long long* a, int size, int index) {
    bool res = true;
    if (left(index) < size) {
        if (a[left(index)] < a[index])
            res = isHeap_helper(a, size, left(index));
        else
            return false;
    }

    if (!res)
        return false;

    if (right(index) < size) {
        if (a[right(index)] < a[index]) {
            res = isHeap_helper(a, size, right(index));
        }
        else
            return false;
    }

    return res;
}

bool isHeap(long long* a, int size) {
    return isHeap_helper(a, size, 0);
}

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        cout << isHeap(arr, n) << endl;
    }
    return 0;
}