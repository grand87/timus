#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int arr[10000];
/*
vector<int> reverse(vector<int> a) {
    for (size_t i = 0; i < a.size() / 2; i++) {
        swap(a[i], a[a.size() - i - 1]);
    }
    return a;
}

vector<int> intToNumberArray(int value) {
    vector<int> result;
    while (value != 0) {
        int rem = value % 10;
        result.push_back(rem);
        value = value / 10;
    }
    return reverse(result);
}

vector<int> addBig(vector<int> a, vector<int> b) {
    vector<int> res;

    if (a.size() < b.size())
        swap(a, b);

    int carry = 0;
    int digit = 0;
    for (size_t i = 0; i < b.size(); i++) {
        digit = b[b.size() - i - 1] + a[a.size() - i - 1] + carry;
        if (digit >= 10) {
            digit %= 10;
            carry = 1;
        }
        else
            carry = 0;
        res.push_back(digit);
    }

    for (size_t i = b.size(); i < a.size(); i++) {
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
    vector<int> res = { 0 };

    if (a.size() < b.size())
        swap(a, b);

    int carry = 0;
    int digit = 0;
    for (size_t i = 0; i < b.size(); i++) {
        vector<int> product;
        for (size_t z = 0; z < i; z++)
            product.push_back(0);
        for (size_t j = 0; j < a.size(); j++) {
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

class BigInt {
public:
    BigInt(int value) {
        isPositive = value >= 0;
        if (!isPositive)
            value *= -1;
        data = intToNumberArray(value);
    }

    BigInt(const vector<int>& data, bool isPositive = true) {
        this->data = data;
        this->isPositive = isPositive;
    }

private:
    bool isPositive;
    vector<int> data;

    friend BigInt operator*(const BigInt& a, const BigInt& b);
    friend BigInt max(const BigInt& a, const BigInt& b);
    friend BigInt min(const BigInt& a, const BigInt& b);
    friend ostream& operator << (ostream &out, const BigInt& a);
};

BigInt operator*(const BigInt& a, const BigInt& b) {
    return BigInt(mulBig(a.data, b.data), (a.isPositive && b.isPositive) || (!a.isPositive && !b.isPositive));
}

BigInt max(const BigInt& a, const BigInt& b) {
    if (a.isPositive && !b.isPositive)
        return a;
    if (!a.isPositive && b.isPositive)
        return b;
    if (a.isPositive && b.isPositive) {
        //both positive
        if (a.data.size() > b.data.size())
            return a;
        if (a.data.size() < b.data.size())
            return b;
        for (size_t i = 0; i < a.data.size(); i++) {
            if (a.data[i] > b.data[i])
                return a;
            else if (a.data[i] < b.data[i])
                return b;
        }
        //equals
        return a;
    } else {
        //both negative
        if (a.data.size() > b.data.size())
            return b;
        if (a.data.size() < b.data.size())
            return a;
        for (size_t i = 0; i < a.data.size(); i++) {
            if (a.data[i] > b.data[i])
                return b;
            else if (a.data[i] < b.data[i])
                return a;
        }
        //equals
        return a;
    }
}

BigInt min(const BigInt& a, const BigInt& b) {
    if (a.isPositive && !b.isPositive)
        return b;
    if (!a.isPositive && b.isPositive)
        return a;
    if (a.isPositive && b.isPositive) {
        //both positive
        if (a.data.size() > b.data.size())
            return b;
        if (a.data.size() < b.data.size())
            return a;
        for (size_t i = 0; i < a.data.size(); i++) {
            if (a.data[i] > b.data[i])
                return b;
            else if (a.data[i] < b.data[i])
                return a;
        }
        //equals
        return a;
    }
    else {
        //both negative
        if (a.data.size() > b.data.size())
            return a;
        if (a.data.size() < b.data.size())
            return b;
        for (size_t i = 0; i < a.data.size(); i++) {
            if (a.data[i] > b.data[i])
                return a;
            else if (a.data[i] < b.data[i])
                return b;
        }
        //equals
        return a;
    }
}

ostream& operator << (ostream &out, const BigInt& a) {
    for (vector<int>::const_iterator it = a.data.begin(); it != a.data.end(); it++) {
        out << *it;
    }
    return out;
}
*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        long long int prev_max_product = arr[0];
        long long int prev_min_product = arr[0];
        long long int cur_max_product = arr[0];
        long long int cur_min_product = arr[0];

        long long int ans = arr[0];

        for (int j = 1; j < n; j++) {
            auto a1 = prev_max_product * arr[j];
            auto a2 = prev_min_product * arr[j];
            auto a3 = arr[j];

            cur_max_product = max(prev_max_product * arr[j], max(prev_min_product * arr[j], arr[j]));
            cur_min_product = min(prev_max_product * arr[j], min(prev_min_product * arr[j], arr[j]));

            ans = max(ans, cur_max_product);

            prev_max_product = cur_max_product;
            prev_min_product = cur_min_product;
        }

        cout << ans << endl;
    }

    return 0;
}