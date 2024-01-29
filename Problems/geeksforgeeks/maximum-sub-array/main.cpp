#include <iostream>

using namespace std;

int arr[100];
int sumInPos[100];
int lenInPos[100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
            cin >> arr[j];

        sumInPos[0] = arr[0] > 0 ? arr[0] : 0; ;
        int len = sumInPos[0] > 0 ? 1 : 0;
        lenInPos[0] = len;
        int lastLen = 0;

        for (int j = 1; j < n; j++) {
            if (arr[j] < 0) {
                sumInPos[j] = 0;
                lenInPos[j] = 0;
                len = 0;
            }
            else {
                sumInPos[j] += sumInPos[j - 1] + arr[j];
                len++;
                lenInPos[j] = len;
                if (len > lastLen)
                    lastLen = len;
            }
        }

        //search for the segment with the biggest sum
        int maxSum = sumInPos[0];
        int pos = 0;
        for (int j = 1; j < n; j++) {
            if (sumInPos[j] > maxSum) {
                pos = j;
                maxSum = sumInPos[j];
            } else if ((sumInPos[j] == maxSum) && (lenInPos[pos] < lenInPos[j])) {
                pos = j;
            }
        }

        //now need to print from pos - len to pos
        for (int j = 0; j < lenInPos[pos]; j++) {
            cout << arr[pos - lenInPos[pos] + j + 1] << " ";
        }
        cout << endl;
    }
    return 0;
}