#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), [](const string& a, const string& b) -> bool {
        if (a.length() < b.length())
            return true;
        if (a.length() > b.length())
            return false;

        const bool aIsSmaller = strcmp(a.c_str(), b.c_str()) < 0;

        return aIsSmaller;
    });

    return unsorted;
}

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
    ostream& fout = cout;
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
#ifndef LOCAL_TEST
    fout.close();
#endif
    return 0;
}
