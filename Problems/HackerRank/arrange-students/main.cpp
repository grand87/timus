#include <utils.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool arrangeStudentsHelper(const vector<int>& a, const vector<int>& b) {
    unsigned int i = 0;
    for (; i < a.size(); i++) {
        if (a[i] > b[i])
            break;
        if (i > 0 && a[i] < b[i - 1])
            break;
    }
    return i == a.size();
}

string arrangeStudents(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    const bool res = arrangeStudentsHelper(a, b) | arrangeStudentsHelper(b, a);
    return res ? "YES" : "NO";
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; ++t) {
        int count = 0;
        cin >> count;

        vector<int> boys(count);
        vector<int> girls(count);

        readVector(cin, boys, count);
        readVector(cin, girls, count);

        cout << arrangeStudents(boys, girls) << endl;
    }
    return 0;
}