#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    const int size = A.size();
    if(size != 0 && K % size != 0) {
        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            result[(i + K) % size] = A[i];
        }
        return result;
    }
    return A;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int n,k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> a = solution(b, k);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}