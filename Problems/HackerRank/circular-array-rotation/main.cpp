#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

void reverse(int* arr, int pos, int count) {
    int end = pos + count - 1;
    while (pos < end) {
        swap(arr[pos], arr[end]);
        ++pos;
        --end;
    }
}

// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    k = k % a.size();
    if (k > 0) {
        //reverse(a.begin(), a.begin() + k + 1);
        //reverse(a.begin() + k + 1, a.end());
        //reverse(a.begin(), a.end());

        if (k < a.size() / 2) {
            k = a.size() - k;
        } else {
            k = a.size() - k;
        }

        if(k > 1)
            reverse(&a[0], 0, k);

        reverse(&a[0], k, a.size() - k);
        reverse(&a[0], 0, a.size());
    }
    vector<int> res;
    res.reserve(queries.size());
    
    for (int q : queries)
        res.push_back(a[q]);
    return res;
}

int main()
{
#ifdef LOCAL_TEST
    ifstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
    ostream &fout = cout;
#elif
    ofstream fout(getenv("OUTPUT_PATH"));
#endif
    string nkq_temp;
    getline(cin, nkq_temp);

    vector<string> nkq = split_string(nkq_temp);

    int n = stoi(nkq[0]);

    int k = stoi(nkq[1]);

    int q = stoi(nkq[2]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = circularArrayRotation(a, k, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
#ifndef LOCAL_TEST
    fout.close();
#endif
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
