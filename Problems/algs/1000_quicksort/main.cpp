#include <iostream>
#include <fstream>
#include <utils.h>

using namespace std;

vector<int>::iterator myQSortPartition(vector<int>::iterator begin, vector<int>::iterator end) {

}

void myQSort(vector<int>::iterator begin, vector<int>::iterator end) {
    while (end - begin > 1) {
        //split array on 2 parts
        vector<int>::iterator pivot = myQSortPartition(begin, end);
        myQSort(pivot, end);
        end = pivot;
    }
}

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    int t;
    cin >> t;

    for (int testCase = 0; testCase < t; testCase++) {
        int n;
        cin >> n;

        vector<int> arr(n);
        readVector(cin, arr, n);

        myQSort(arr.begin(), arr.end());

        printVector(cout, arr);

        cout << endl;
    }
    return 0;
}