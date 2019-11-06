#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void genPrimeNumbers(int range, vector<char> &buffer) {
    fill(buffer.begin(), buffer.begin() + range, 1);

    for (int i = 2; i*i <= range; i++) {
        if (buffer[i] == 1) {
            for (int p = i*i; p <= range; p+=i) {
                buffer[p] = 0;
            }
        }
    }
}

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    vector<char> buffer;
    buffer.resize(100000);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        genPrimeNumbers(n + 1, buffer);
        for (int i = 2; i <= n; i++) {
            if (buffer[i] == 1)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}