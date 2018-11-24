#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int res = A[0];
    for (int i = 1; i < A.size(); i++)
        res ^= A[i];
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int a = solution(b);
    cout << a;
}