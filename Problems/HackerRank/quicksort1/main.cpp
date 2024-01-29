#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

vector<string> split_string(string);

// Complete the quickSort function below.
vector<int> quickSort(vector<int> arr) {
    const int pivot = arr[0];
    int smallerFromTheEnd = arr.size() - 1;
    int pos = 1;
    int pivotPos = 0;
    while (pos <= smallerFromTheEnd) {
        if (pos == pivotPos) {
            pos++;
        } else if (arr[pos] == pivot) {
            pos++;
            continue;
        } else if (arr[pos] < pivot) {
            swap(arr[pos], arr[pivotPos]);
            pivotPos = pos;
            pos++;
            continue;
        } else {
            //locate the position from the end which is smaller then pivot and swap them
            bool swapped = false;
            for (int i = smallerFromTheEnd; i > pos; i--) {
                if (arr[i] < pivot) {
                    swap(arr[i], arr[pos]);
                    smallerFromTheEnd = i - 1;
                    swapped = true;
                    break;
                }
            }
            if (swapped)
                continue;
            //on the next cycle the item in the arr[pos] will be mvoed to the left partition
            //no need to increase pos;
        }
        //means item is on it's position
        pos++;
    }

    return arr;
}

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
    ostream& fout = cout;
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

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

    vector<int> result = quickSort(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
