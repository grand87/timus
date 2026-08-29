#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif

    int n, k;
    std::cin >> n >> k;

    list<int> p;
    for (int i = 1; i <= n; i++) {
        p.push_front(i);
    }

    // remove first round

    int pos = k;
    list<int>::reverse_iterator toRemove = p.rbegin();
    advance(toRemove, pos - 1);

    for (int i = 1; i < n; i++) {
        
        
        
        
        
        
        int pos = k % p.size() - 1;

        list<int>::iterator removed;

        if (pos == 0) {
            removed = p.erase(p.begin());
        } else {
            removed = p.erase(next(p.begin(), pos - 1));
        }

        cout << *removed;
        if (i + i < n) {
            cout << " ";
        }
    }

    return 0;
}
