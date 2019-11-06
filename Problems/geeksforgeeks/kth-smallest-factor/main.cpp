#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long smallestFactor(long long n, long long k) {
    //first find all didisors

    vector<long long> divisors;

    long long maxDivider = sqrt(n);

    //generate vector of all possible dividers
    for (long long i = 1; i <= maxDivider; i++) {
        if (n % i == 0) {
            if(n / i == i)
                divisors.push_back(i);
            else {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());
    
    if (k <= divisors.size())
        return divisors[k - 1];
    else
        return -1;
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
        long long n, k;
        cin >> n >> k;
        cout << smallestFactor(n, k) << endl;
    }
    return 0;
}