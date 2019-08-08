#include <algorithm>
#include <assert.h>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utils.h>
#include <vector>

using namespace std;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    bool isOne = n & 1;
    n >>= 1;
    isOne = !isOne;
    while (n > 0) {
      if ((n & 0b1) != isOne) {
        return false;
      }
      n >>= 1;
      isOne = !isOne;
    }

    return true;
  }
};

int main() {
#ifdef LOCAL_TEST
  std::ifstream in("input.txt");
  cin.set_rdbuf(in.rdbuf());
#endif

  int t;
  cin >> t;
  Solution s;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << s.hasAlternatingBits(n) << endl;
  }

  return 0;
}
