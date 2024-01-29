#include <fstream>
#include <iostream>

using namespace std;

class Solution {

public:
    int getSum(int a, int b) {

        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }

        return a;
    }
};

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        Solution s;
        cout << s.getSum(a, b) << endl;
    }

    return 0;
}