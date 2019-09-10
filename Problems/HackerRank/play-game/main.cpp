#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the bricksGame function below.
 */

vector<long> vals[2];
vector<long> sums;
int arrSize = 0;

int bricksGameHelp(int* a, int pos, int count, bool secondGamer) {
    if (count == 0)
        return 0;

#ifdef LOCAL_TEST
    cout << "look for gamer " << secondGamer << " start from pos " << pos << endl;
#endif

    if (vals[secondGamer][pos] > 0)
        return vals[secondGamer][pos];

    int totalInRange = sums[arrSize - 1];

    if (count > 0) {
        long strategy1 = a[pos];
        if (count - 1 > 0) {
            strategy1 += totalInRange - bricksGameHelp(a, pos + 1, count - 1, !secondGamer) - sums[pos];
        }
        vals[secondGamer][pos] = max(vals[secondGamer][pos], strategy1);
    }

    if (count > 1) {
        long strategy2 = a[pos] + a[pos + 1];
        if (count > 2) {
            strategy2 += totalInRange - bricksGameHelp(a, pos + 2, count - 2, !secondGamer) - sums[pos + 1];
        }
        vals[secondGamer][pos] = max(vals[secondGamer][pos], strategy2);
    }

    if (count > 2) {
        long strategy3 = a[pos] + a[pos + 1] + a[pos + 2];
        if (count > 3) {
            strategy3 += totalInRange - bricksGameHelp(a, pos + 3, count - 3, !secondGamer) - sums[pos + 2];
        }
        vals[secondGamer][pos] = max(vals[secondGamer][pos], strategy3);
    }
#ifdef LOCAL_TEST
    cout << "gamer " << secondGamer << " start from pos " << pos << " gains " << vals[secondGamer][pos] << endl;
#endif
    return vals[secondGamer][pos];
}

int bricksGame(vector<int> arr) {
    /*
     * Write your code here.
     */
    vals[0].resize(arr.size());
    vals[1].resize(arr.size());

    fill(vals[0].begin(), vals[0].end(), -1);
    fill(vals[1].begin(), vals[1].end(), -1);

    arrSize = arr.size();

    sums.resize(arr.size());
    sums[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        sums[i] = sums[i - 1] + arr[i];
    }

    const int val = bricksGameHelp(&arr[0], 0, arr.size(), false);

    return val;
}

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
    ostream& fout = cout;
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = bricksGame(arr);

        fout << result << "\n";
    }
#ifndef LOCAL_TEST
    fout.close();
#endif
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
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
