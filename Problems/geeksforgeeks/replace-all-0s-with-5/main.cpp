#include <iostream>

using namespace std;
int convertFive(int n);

// Driver program to test above function
int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
int convertFive(int n)
{
    int tmp = 0;
    while (n > 0) {
        int d = n % 10;
        if (d == 0)
            tmp = tmp*10 + 5;
        else
            tmp = tmp*10 + d;
        n /= 10;
    }

    int tmp2 = 0;
    while (tmp > 0) {
        int d = tmp % 10;
        tmp2 = tmp2 * 10 + d;
        tmp /= 10;
    }
    return tmp2;
}