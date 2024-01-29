#include <iostream>
#include <stack>
#include <vector>

using namespace std;
bool isSubSequence(vector<int> s1, vector<int> s2, int m, int n)
{

    if (m == 0) return true;
    if (n == 0) return false;


    if (s1[m - 1] == s2[n - 1])
        return isSubSequence(s1, s2, m - 1, n - 1);


    return isSubSequence(s1, s2, m, n - 1);
}
vector<int> find3Numbers(vector<int>, int);
// Driver program to test above function
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> res = find3Numbers(a, n);

        if (res.size() == 0)
        {
            cout << 0 << endl;
        }
        else if (res[0] < res[1] && res[1] < res[2])
            cout << isSubSequence(res, a, res.size(), n) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> A, int N)
{
    vector < vector<int> > numbers;
    int res = -1;
    numbers.push_back(vector<int>());
    numbers[0].push_back(A[0]);
    for (int j = 1; j < N; j++) {
        bool insterted = false;
        for (int i = 0; i < numbers.size(); i++) {
            if (A[j] > numbers[i][numbers[i].size() - 1]) {
                numbers[i].push_back(A[j]);
                insterted = true;
                if (numbers[i].size() == 3)
                    return numbers[i];
            }
        }
        if (!insterted) {
            numbers.push_back(vector<int>());
            numbers[numbers.size() - 1].push_back(A[j]);
        }
    }
        
    return vector<int>();
}

