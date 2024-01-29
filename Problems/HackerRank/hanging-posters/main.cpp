#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* Complete the 'solve' function below.
*
* The function accepts following parameters:
*  1. INTEGER n
*  2. INTEGER_ARRAY a
*/

double avg(int onField, int OffFiled, double count) {
    return (onField + OffFiled) / count;
}

void solve(int n, vector<int> a) {
    sort(a.begin(), a.end(), greater<int>());

    int onField = accumulate(a.begin(), a.begin() + n, 0);
    int offField = accumulate(a.begin() + n, a.end(), 0);

    int i = 0;
    while (avg(onField, offField, n - i) < a[i] && i < n) {
        onField -= a[i];
        i++;
    }

    cout << setprecision(16) << avg(onField, offField, n - i) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    ostream& fout = cout;
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(k);

    for (int i = 0; i < k; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    solve(n, a);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
