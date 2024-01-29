/* Enter your macros here */
#define INF 100000000
#define toStr(msg) #msg
#define io(v) cin >> v
#define FUNCTION(apiname, operand) \
    void apiname(int &val, int ref) { \
        if (ref operand val) \
            val = ref; \
    }
#define foreach(container, index) for (int index = 0; index < container.size(); index++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result = ) << ' ' << ans;
    return 0;
}