#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStack {
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/
/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack::sort()
{
    vector<int> tmpStore(s.size());
    int i = 0;
    while (!s.empty()) {
        tmpStore[i++] = s.top();
        s.pop();
    }
    std::sort(tmpStore.begin(), tmpStore.end(), [](int a, int b) -> bool {return a < b; });
    for (auto v : tmpStore)
        s.push(v);
}
