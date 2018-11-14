#include <iostream>
#include <string>

using namespace std;

unsigned long calculateFact(unsigned int n, unsigned int k, unsigned int remain)
{
    if (n == remain)
        return remain;
    else
        return n * calculateFact(n - k, k, remain);
}

unsigned long calculateFactIterative(unsigned int n, unsigned int k, unsigned int remain)
{
    unsigned long result = 1;
    while (n != remain)
    {
        result *= n;
        if (n > k)
            n -= k;
        else
            break;
    }
    return result * remain;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    unsigned int n;
    cin >> n;

    std::string lenk;
    getline(cin, lenk);

    unsigned int k = lenk.size() - 1;

    if ((n % k) == 0)
        cout << calculateFactIterative(n, k, 1);
    else
        cout << calculateFactIterative(n, k, n % k);
}