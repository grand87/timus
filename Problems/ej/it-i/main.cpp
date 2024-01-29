#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int primeNumbers[1000000];

int generatePrimes(int* table, int maxValue) {
    int primes = 4;
    primeNumbers[0] = 1;
    primeNumbers[1] = 2;
    primeNumbers[2] = 3;
    primeNumbers[3] = 5;

    for (int i = 6; i < maxValue; i++) {
        int j = 0;
        for (j = 1; j < primes; j++) {
            if (primeNumbers[j] > int(sqrt(i) + 1)) {
                primeNumbers[primes] = i;
                primes++;
                break;
            }
            if (i % primeNumbers[j] == 0) {
                break;
            }
        }
        if (j == primes) {
            primeNumbers[primes] = i;
            primes++;
        }
    }
    return primes;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//#endif
    int queryCount;
    cin >> queryCount;

    // need to precalculate prime numbers from 1 to 1000000
    int primesCount = generatePrimes(primeNumbers, 1000000);

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        // find first number > l;
        // find first numbr < r;
        int* lower = std::upper_bound(primeNumbers, primeNumbers + primesCount, l);
        if (*lower > l && *(lower - 1) == l)
            lower--;
        int* upper = std::lower_bound(primeNumbers, primeNumbers + primesCount, r);
        if (*upper > r)
            upper--;
        
        int primeCountInRange = distance(lower, upper) + 1;

        cout << primeCountInRange << endl;
    }

    return 0;
}