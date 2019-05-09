#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
void readArray(T* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

template<typename T>
void printArray(T* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

template<typename T>
void reverseArray(T* data, int pos, int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(data[pos + i], data[pos + size - 1 - i]);
    }
}

int arr[10000000];

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        readArray(arr, n);
        const int maxValue = *max_element(arr, arr + n);
        const int minValue = *min_element(arr, arr + n);

        //hasing all values
        int hash[100001] = { 0 };

        for (int j = 0; j < n; j++) {
            hash[arr[j]]++;
        }

        int k;
        cin >> k;

        int el = 0;
        for (int j = minValue; j <= maxValue; j++) {
            el += hash[j];
            if (el >= k) {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}
