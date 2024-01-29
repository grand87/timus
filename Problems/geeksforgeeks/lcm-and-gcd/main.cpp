#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long lgd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    while (a > b) {
        a = a % b;
        if (a == 0)
            return b;
        if (a < b)
            swap(a, b);
    }

    return a;
}

long long lcm(long long a, long long b) {
    return a * b / lgd(a, b);
}

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;
        cout << lcm(a, b) << " " << lgd(a, b) << endl;
    }
    return 0;
}