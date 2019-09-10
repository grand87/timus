#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        const int tmp = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] > tmp) {
                //need to shift items in the range arr[j]..arr[i - 1] to right on one position
                if (i - j == 1) {
                    swap(arr[j], arr[i]);
                } else {
                    //shift items
                    for (int k = i; k > j; k--) {
                        arr[k] = arr[k - 1];
                    }
                    arr[j] = tmp;
                }
                break;
            }
        }
    }
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int count;
    cin >> count;

    vector<int> arr(count);
    for (int i = 0; i < count; i++)
        cin >> arr[i];

    insertionSort(arr);

    for (int a : arr)
        cout << a << " ";
    cout << endl;

    return 0;
}
