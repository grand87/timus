#include <algorithm>
#include <iostream>
#include <fstream>
#include <utils.h>

using namespace std;

void solution(vector<unsigned long> &a, vector<unsigned long> &b) {
    const int cap1 = a.size();
    const int cap2 = b.size();

    int pos1 = 0;
    int pos2 = 0;

    while (pos1 + pos2 < cap1 && pos2 < cap2) {
        if (a[pos1] <= b[pos2]) {
            pos1++;
        } else {
            pos2++;
        }
    }

    //array 1 need to contain pos1 items from a following pos2 items from b

    const int insertionStart = cap1 - pos2;

    for (int i = 0; i < pos2; i++) {
        swap(a[insertionStart + i], b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void test1() {
    vector<unsigned long> arr1(100000);
    for (int i = 0; i < 100000; i++)
        arr1[i] = i + 1;

    vector<unsigned long> arr2(20000);
    for (int i = 0; i < 20000; i++)
        arr2[i] = i + 1;

    solution(arr1, arr2);

    printVector(cout, arr1);
    printVector(cout, arr2);
}

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());

    test1();
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<unsigned long> arr1(n);
        readVector(cin, arr1, n);
        vector<unsigned long> arr2(m);
        readVector(cin, arr2, m);

        solution(arr1, arr2);

        printVector(cout, arr1);
        printVector(cout, arr2);
        cout << endl;
    }
    return 0;
}