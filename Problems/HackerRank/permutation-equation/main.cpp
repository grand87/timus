#include <iostream>
#include <vector>

using namespace std;

int getIndexForValue(const vector<int>& p, int search) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == search) {
            return i;
        }
    }
    return -1;
}

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
    vector<int> result(p.size());

    vector<int> p1(p.size() + 1);

    for (int i = 0; i < p.size(); i++) {
        p1[p[i]] = i+1;
    }

    for (int i = 1; i <= p.size(); i++) {
        int indexForValue = p1[i];
        indexForValue = p1[indexForValue];
        result[i - 1] = indexForValue;
    }
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;

    vector<int > data;

    for (int i = 0; i < t; i++) {
        int val;
        cin >> val;
        data.push_back(val);
    }

    vector<int> res = permutationEquation(data);

    for (int i = 0; i < t; i++) {
        cout << res[i] << " ";
    }

    return 0;
}
