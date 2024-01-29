#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <assert.h>

using namespace std;
using namespace chrono;

vector<int> stringToNumberArray(const string &value) {
    vector<int> result(value.size());
    for (int i = 0; i < value.size(); i++) {
        result[i] = value[i] - '0';
    }
    return result;
}

//void reverse(vector<int> &a) {
//    const int count = a.size();
//    const int halfCount = count / 2;
//    
//    for (int i = 0; i < halfCount; i++) {
//        const int tmp = a[count - i - 1];
//        a[count - i - 1] = a[i];
//        a[i] = tmp;
//    }
//}

vector<int> addBig(vector<int> &a, vector<int> &b) {
    if (a.size() < b.size())
        swap(a, b);

    vector<int> res;
    res.reserve(a.size() + 1);


    int carry = 0;
    int digit = 0;
    for (int i = 0; i < b.size(); i++) {
        digit = b[b.size() - i - 1] + a[a.size() - i - 1] + carry;
        if (digit >= 10) {
            digit %= 10;
            carry = 1;
        }
        else
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

    reverse(res.begin(), res.end());
    return res;
}

vector<int> mulBig(vector<int> &a, vector<int> &b, vector<int> &product) {
    vector<int> res = { 0 };

    if (a.size() < b.size())
        swap(a, b);

    int carry = 0;
    int digit = 0;
    for (int i = 0; i < b.size(); i++) {
        product.resize(0);
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
        
        reverse(product.begin(), product.end());
        res = addBig(res, product);
    }

    return res;
}

ostream& operator << (ostream& stream, const vector<int>& vec) {
    for (int a : vec)
        stream << a;
    return stream;
}

int main() {
    string t0, t1;
    int n;
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    cin >> t0 >> t1 >> n;

    vector<vector<int>> dpResults(n + 1);
    dpResults[0] = stringToNumberArray(t0);
    dpResults[1] = stringToNumberArray(t1);

    vector<int> product;
    product.reserve(1000000);

#ifdef LOCAL_TEST
    vector<int> a {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8};
    vector<int> b { 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8 };
    vector<int> res = mulBig(a, b, product);
    assert(res.size() < 40 && "result size is worng");
#endif

    // iterative approach to calculate the values - dp from bottom to top
    for (int i = 2; i < n; i++) {
#ifdef LOCAL_TEST
        system_clock::time_point start = system_clock::now();
#endif
        product.resize(0);
        vector<int> res = mulBig(dpResults[i - 1], dpResults[i - 1], product);
        cout << "product size is " << res.size() << endl;
        dpResults[i] = addBig(res, dpResults[i - 2]);
#ifdef LOCAL_TEST
        system_clock::time_point end = system_clock::now();
        cout << "processing item " << i << " tooks " << duration_cast<milliseconds>(end - start).count() << "ms" << " to calculate " << dpResults[i].size() << " elements\n";
//        cout << dpResults[i] << endl;
#endif
    }

    cout << dpResults[n - 1];

    return 0;
}
