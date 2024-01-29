#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int myGCD(int a, int b) {
    if (a == b)
        return a;

    while (b != 0) {
        a = a % b;
        if (a < b)
            swap(a, b);
    }
    return a;
}

void addFraction(int num1, int den1, int num2, int den2)
{
    //find least common factor - LCF for den1 & den2

    int lcf = (den1 * den2) / myGCD(den1, den2);
    num1 *= lcf / den1;
    num2 *= lcf / den2;

    int resNum = num1 + num2;
    int gcdRes = myGCD(resNum, lcf);

    cout << resNum / gcdRes << "/" << lcf / gcdRes << endl;
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

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        addFraction(a, b, c, d);
    }
    return 0;
}