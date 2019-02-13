#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> stringToNumberArray(string value) {
    vector<int> result(value.size());
    for (int i = 0; i < value.size(); i++) {
        result[i] = value[i] - '0';
    }
    return result;
}

vector<int> reverse(vector<int> a) {
    for (int i = 0; i < a.size() / 2; i++) {
        swap(a[i], a[a.size() - i - 1]);
    }
    return a;
}

vector<int> addBig(vector<int> a, vector<int> b) {
    vector<int> res;

    if (a.size() < b.size())
        swap(a, b);

    int carry = 0;
    int digit = 0;
    for (int i = 0; i < b.size(); i++) {
        digit = b[b.size() - i - 1] + a[a.size() - i - 1] + carry;
        if (digit >= 10) {
            digit %= 10;
            carry = 1;
        } else
            carry = 0;
        res.push_back(digit);
    }

    for (int i = b.size(); i < a.size(); i++) {
        digit = a[a.size() - i - 1] + carry;
        if (digit >= 10) {
            digit %= 10;
            carry = 1;
        }
        else
            carry = 0;
        res.push_back(digit);
    }
    if (carry == 1) {
        res.push_back(1);
    }

    return reverse(res);
}

vector<int> mulBig(vector<int> a, vector<int> b) {
    vector<int> res = {0};

    if (a.size() < b.size())
        swap(a, b);

    int carry = 0;
    int digit = 0;
    for (int i = 0; i < b.size(); i++) {
        vector<int> product;
        for (int z = 0; z < i; z++)
            product.push_back(0);
        for (int j = 0; j < a.size(); j++) {
            digit = a[a.size() - j - 1] * b[b.size() - i - 1] + carry;
            if (digit >= 10) {
                carry = digit / 10;
                digit %= 10;
            }
            else
                carry = 0;
            product.push_back(digit);
        }
        if (carry) {
            product.push_back(carry);
            carry = 0;
        }
        product = reverse(product);
        res = addBig(res, product);
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    string t0, t1;
    int n;
    cin >> t0 >> t1 >> n;

    vector<vector<int>> dpResults;
    dpResults.push_back(stringToNumberArray(t0));
    dpResults.push_back(stringToNumberArray(t1));

    vector<int> b = { 7,4,4 };
    vector<int> a = { 2,7 };
    //vector<int> b = { 2,7 };
    //vector<int> a = { 5 };
    b = mulBig(b, b);
    a = addBig(a, b);

    // iterative approach to calculate the values - dp from bottom to top
    for (int i = 2; i < n; i++) {
        dpResults.push_back(addBig(dpResults[i - 2], mulBig(dpResults[i - 1], dpResults[i - 1])));
    }

    for (int i = 0; i < dpResults[n - 1].size(); i++) {
        cout << dpResults[n - 1][i];
    }

    return 0;
}
