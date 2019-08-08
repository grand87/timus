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

  stack<char> read(const string &s) {
    stack<char> s1;
    for (char c : s) {
      if (c == '#') {
        if (!s1.empty())
          s1.pop();
      } else
        s1.push(c);
    }
    return s1;
  }

  bool stackImpl(const string &S, const string &T) {
    stack<char> s1 = read(S);
    stack<char> s2 = read(T);

    if (s1.size() == s2.size()) {
      while (!s1.empty() && !s2.empty()) {
        if (s1.top() != s2.top())
          return false;
        s1.pop();
        s2.pop();
      }
      return s1.empty() && s2.empty();
    }
    return false;
  }

public:
  bool backspaceCompare(string S, string T) { return stackImpl(S, T); }
};

int main() {
#ifdef LOCAL_TEST
  std::ifstream in("input.txt");
  cin.set_rdbuf(in.rdbuf());
#endif

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string a;
    cin >> a;

    string b;
    cin >> b;

    Solution s;
    cout << s.backspaceCompare(a, b) << endl;
  }
  return 0;
}
