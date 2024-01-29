#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {

    int globalMaxSubArray = arr[0];
    int currentMax = globalMaxSubArray;

    int gloablMaxSequence = arr[0];
    int currentMaxSequence = gloablMaxSequence;

    for (int i = 1; i < arr.size(); i++) {
        const int a = arr[i];
        currentMax = max(currentMax + a, a);
        globalMaxSubArray = max(globalMaxSubArray, currentMax);

        currentMaxSequence = max(currentMaxSequence, max(currentMaxSequence + arr[i], arr[i]));
        gloablMaxSequence = max(gloablMaxSequence, currentMaxSequence);
    }

    return vector<int> {globalMaxSubArray, gloablMaxSequence};
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif    

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

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
