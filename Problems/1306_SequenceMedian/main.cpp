#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 250000;
const int MAX_N_MIDLE = MAX_N / 2;

const unsigned int MAX_VALUE = -1;
const unsigned int MID_VALUE = MAX_VALUE / 2;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int n;
    unsigned int v = 0;
    vector<unsigned int> container;
    container.reserve(MAX_N_MIDLE + 1);
    priority_queue <unsigned int, vector<unsigned int>> q(std::less<unsigned int>(), std::move(container));
    
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(1);

    cin >> n;

    int i;
    for (i = 0; i < n / 2 + 1; ++i)
    {
        cin >> v;
        q.push(v);
    }

    int top = q.top();

    for(;i < n; ++i)
    {
        cin >> v;
        if (v < q.top())
        {
            q.pop();
            q.push(v);
        }
    }

    if (n % 2 == 1)
    {
        cout << q.top();
    }
    else
    {
        unsigned int v1 = q.top();
        q.pop();
        unsigned int v2 = q.top();
        std::cout << (double)(v1 + v2) / 2.0;
    }
}