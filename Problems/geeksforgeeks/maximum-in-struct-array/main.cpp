#include<iostream>
#include<algorithm>


using namespace std;
struct Height {
    int feet;
    int inches;
};
int findMax(Height arr[], int n);
// driver program

Height arr[100001];

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, tmp1, tmp2;
        cin >> n;
        for (int i = 0; i<n; i++)
        {
            cin >> tmp1 >> tmp2;
            arr[i] = { tmp1, tmp2 };
        }
        int res = findMax(arr, n);
        cout << res << endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

int toInch(const Height& h) {
    return h.feet * 12 + h.inches;
}

/*
Structure of the element of the array is as
struct Height {
int feet;
int inches;
};
*/
// function must return the maximum Height
// return the height in inches
int findMax(Height arr[], int n)
{
    return toInch(*max_element(arr, arr + n, [](const Height& a, const Height& b) {return toInch(a) < toInch(b); }));
}

