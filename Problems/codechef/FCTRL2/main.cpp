#include <iostream>

using namespace std;

class BigInt
{
    int v[200];
    int m;
public:
    BigInt(int av = -1)
    {
        if (av == -1) {
            m = 0;
            return;
        }

        char bfr[10];
        sprintf(bfr, "%d", av);
        int index = 0;
        std::string str(bfr);
        for (const char c : str) {
            v[str.size() - ++index] = c - '0';
        }
        m = index;
    }

    BigInt(const BigInt& c) {
        for (int i = 0; i < c.m; ++i) {
            v[i] = c.v[i];
        }
        m = c.m;
    }

    void dump() const
    {
        for (int i = m - 1; i >= 0; --i) {
            cout << v[i];
        }
        cout << endl;
    }

    bool isValid() const
    {
        return m != 0;
    }

    BigInt operator*(int r) const
    {
        BigInt c(*this);

        int temp = 0;
        for (int i = 0; i < c.m; ++i) {
            int x = c.v[i] * r + temp;
            c.v[i] = x % 10;
            temp = x / 10;
        }
        while (temp > 0) {
            c.v[c.m++] = temp % 10;
            temp = temp / 10;
        }
        return c;
    }
};

const int maxFact = 101;
BigInt FactCache[maxFact];

const BigInt& f(int fact) {
    if (FactCache[fact].isValid()) {
        return FactCache[fact];
    }

    int n = 0;
    for (int i = fact - 1; i > 0; --i) {
        if (FactCache[i].isValid()) {
            n = i;
            break;
        }
    }

    for (int i = n + 1; i <= fact; ++i) {
        FactCache[i] = FactCache[i - 1] * i;
    }

    return FactCache[fact];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif	
    int t;
    cin >> t;

    FactCache[0] = 0;
    FactCache[1] = 1;
    FactCache[2] = 2;
    for (int i = 3; i < maxFact; ++i) {
        FactCache[i] = -1;
    }

    for (int i = 0; i < t; ++i) {
        unsigned int fact;
        cin >> fact;

        BigInt res = f(fact);
        res.dump();
    }
}