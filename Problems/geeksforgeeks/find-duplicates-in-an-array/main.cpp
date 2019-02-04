#include <iostream>
using namespace std;

/*Complete the function below*/
void printDuplicates(int arr[100], int n)
{
    bool located = false;
    for (int i = 0; i < n; i++) {
        
        const int index = arr[i] % n;
        arr[index] += n;

        if (arr[index] / n == 2) {
            located = true;
            cout << index << " ";
        }

    }
    if (!located)
        cout << "-1";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[100];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        printDuplicates(a, n);
        cout << endl;
    }
    return 0;
}
