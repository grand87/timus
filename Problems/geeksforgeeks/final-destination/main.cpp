#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long x, y, s;
        cin >> x >> y >> s;
        const long totalSteps = abs(x) + abs(y);
        
        if (s > totalSteps) {
            if ((s - totalSteps) % 2 == 0) {
                cout << 1 << endl;
            } else
                cout << 0 << endl;
        } else if (s == totalSteps) {
            cout << 1 << endl;
        } else 
            cout << 0 << endl;
    }
    return 0;
}