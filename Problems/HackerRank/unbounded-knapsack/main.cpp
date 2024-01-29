#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

vector<string> split_string(string);

// Complete the unboundedKnapsack function below.
int select(int k, vector<int> arr, int offset) {
    if (offset >= arr.size())
        return 0;
    //if we choose value in pos offset
    int val1 = 0;
    //is it reasonable to take this value at all
    if (arr[offset] == k)
        return k;
    if (k % arr[offset] == 0)
        return k;
    if (arr[offset] < k) {
        //we could take multiple of arr[offset] - but how many?
        const int value_at_offset_time = k / arr[offset];
        // need to determine max possible with arr[offset] from 1 to value_at_offset_time times
        val1 = arr[offset];
        for (int i = value_at_offset_time; i > 0; i--) {
            int maxSoFar = arr[offset] * i;

            //locate next sutable value to meet arr[offset + 1] < k criteria
            const int rem = k - maxSoFar;
            int suitableOffset = offset + 1;
            for (; suitableOffset < arr.size(); suitableOffset++) {
                if (arr[suitableOffset] < rem)
                    break;
            }
            if (suitableOffset < arr.size()) {
                maxSoFar += select(rem, arr, suitableOffset);
            }
            val1 = max(val1, maxSoFar);
            if (val1 == k)
                return k;
        }
    }
    if (val1 == k)
        return val1;
    int val2 = 0;
    //if we not choose value in pos offset
    for (offset += 1; offset < arr.size(); offset++) {
        if (arr[offset] < k)
            break;
    }
    if(offset < arr.size())
        val2 = select(k, arr, offset);

    return max(val1, val2);
}

int unboundedKnapsack(int k, vector<int> arr) {
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end(), [](int a, int b) -> bool {return b < a; });
    return select(k, sorted_arr, 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    ostream& fout = cout;
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }
#ifndef ONLINE_JUDGE
    auto start = chrono::steady_clock::now();
#endif
    int result = unboundedKnapsack(k, arr);
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    fout << result << " "<< chrono::duration_cast<chrono::milliseconds>(end - start).count() << "\n";
#else
    fout << result << "\n";
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
