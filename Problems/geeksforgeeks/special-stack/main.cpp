#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> item;
item buf[101];
int currentSize = 0;

/*Complete the function(s) below*/
void push(int a) {
    if (currentSize > 0)
        buf[currentSize] = make_pair(a, min(buf[currentSize - 1].second, a));
    else
        buf[currentSize] = make_pair(a, a);
    ++currentSize;
}

bool isFull(int n) {
    return currentSize == n;
}

bool isEmpty() {
    return currentSize == 0;
}

int pop() {
    int result = buf[currentSize].first;
    --currentSize;
    return result;
}

int getMin() {
    return buf[currentSize - 1].second;
}

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n, a;
        cin >> n;
        while (!isEmpty())
            pop();

        while (!isFull(n)) {
            cin >> a;
            push(a);
        }

        cout << getMin() << endl;
    }

    return 0;
}